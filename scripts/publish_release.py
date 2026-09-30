#!/usr/bin/env python3
"""Publish an explicitly selected clean commit using HTTPS git and curl REST.

Credentials stay in process memory/stdin; never embedded in URLs or argv.
Build/scan the assets first. This script does not change or commit source.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import tempfile
from urllib.parse import urlencode, urlparse

REMOTE = 'https://github.com/Blizz127/Companions-Of-Xanth-Decompile'
API = 'https://api.github.com/repos/Blizz127/Companions-Of-Xanth-Decompile'
TOKEN = Path.home() / '.config/github-release.token'


def run(argv, **kwargs):
    result = subprocess.run(argv, capture_output=True, **kwargs)
    if result.returncode:
        # Do not echo server bodies or credential-helper output.
        raise RuntimeError(f'{Path(argv[0]).name} failed (exit {result.returncode})')
    return result.stdout


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--repo', type=Path, default=Path.cwd())
    parser.add_argument('--branch', required=True)
    parser.add_argument('--tag', required=True)
    parser.add_argument('--commit', required=True)
    parser.add_argument('--notes', type=Path, required=True)
    parser.add_argument('--asset', type=Path, action='append', required=True)
    parser.add_argument('--dry-run', action='store_true')
    args = parser.parse_args()
    def git(*argv, **kwargs):
        return run(['git', '-c', 'credential.interactive=true', '-C', str(args.repo), *argv], **kwargs).decode().strip()
    if not re.fullmatch(r'[0-9a-f]{40}', args.commit):
        parser.error('--commit must be the full tested commit SHA')
    git('check-ref-format', 'refs/heads/' + args.branch)
    git('check-ref-format', 'refs/tags/' + args.tag)
    if git('rev-parse', 'HEAD') != args.commit or git('status', '--porcelain'):
        parser.error('repo must be clean and checked out at the tested commit')
    names = [p.name for p in args.asset]
    if len(set(names)) != len(names) or 'SHA256SUMS' in names:
        parser.error('asset basenames must be unique; SHA256SUMS is generated')
    if any(not re.fullmatch(r'[A-Za-z0-9_.-]+', n) for n in names):
        parser.error('asset names must be simple portable filenames')
    checksums = ''.join(f'{digest(p)}  {p.name}\n' for p in args.asset)
    notes = args.notes.read_text()
    if args.dry_run:
        print(json.dumps({'commit': args.commit, 'branch': args.branch,
                          'tag': args.tag, 'sha256sums': checksums}, indent=2))
        return
    # Verify ordinary host connectivity before reading any token.
    run(['curl', '--fail', '--silent', '--show-error', '--max-time', '20', API])
    token = TOKEN.read_text().strip()
    if not re.fullmatch(r'[A-Za-z0-9_]+', token):
        raise RuntimeError('Invalid release token file')

    def curl(url, method='GET', data=None, file=None, accept='application/vnd.github+json'):
        parsed = urlparse(url)
        if parsed.scheme != 'https' or parsed.hostname not in ('api.github.com', 'uploads.github.com'):
            raise RuntimeError('Unexpected API/upload host')
        config = f'header = "Authorization: Bearer {token}"\nheader = "Accept: {accept}"\n'
        argv = ['curl', '--fail', '--silent', '--show-error', '--location',
                '--max-time', '300', '--config', '-', '--request', method, url]
        if file is not None:
            argv += ['--header', 'Content-Type: application/octet-stream', '--data-binary', '@' + str(file)]
        elif data is not None:
            config += 'header = "Content-Type: application/json"\n'
            # Separate payload file from stdin carrying confidential config.
            payload = stage / 'payload.json'
            payload.write_text(json.dumps(data))
            argv += ['--data-binary', '@' + str(payload)]
        return run(argv, input=config.encode())

    with tempfile.TemporaryDirectory(prefix='xanth-publish-') as temporary:
        stage = Path(temporary)
        askpass = stage / 'askpass.py'
        askpass.write_text('#!/usr/bin/env python3\nimport sys\nfrom pathlib import Path\n'
                          'print("x-access-token" if "Username" in sys.argv[1] else '
                          '(Path.home()/".config/github-release.token").read_text().strip())\n')
        askpass.chmod(0o700)
        env = os.environ.copy()
        env.update(GIT_TERMINAL_PROMPT='0', GIT_ASKPASS=str(askpass))
        git('push', REMOTE + '.git', args.commit + ':refs/heads/' + args.branch, env=env)
        remote = git('ls-remote', REMOTE + '.git', 'refs/heads/' + args.branch, env=env)
        if remote.split()[0] != args.commit:
            raise RuntimeError('Remote branch does not match tested commit')
        # Existing tags must resolve to the same tested commit, including annotated tags.
        tagged = git('ls-remote', REMOTE + '.git', 'refs/tags/' + args.tag,
                     'refs/tags/' + args.tag + '^{}', env=env)
        if tagged:
            pairs = dict(line.split()[::-1] for line in tagged.splitlines())
            if pairs.get('refs/tags/' + args.tag + '^{}', pairs.get('refs/tags/' + args.tag)) != args.commit:
                raise RuntimeError('Existing tag points to a different commit')
        releases = json.loads(curl(API + '/releases?per_page=100'))
        existing = next((r for r in releases if r['tag_name'] == args.tag), None)
        if existing:
            raise RuntimeError('Release already exists; inspect it before retrying')
        release = json.loads(curl(API + '/releases', 'POST', data={
            'tag_name': args.tag, 'target_commitish': args.commit,
            'name': 'Companions of Xanth port ' + args.tag, 'body': notes,
            'prerelease': True, 'draft': False, 'make_latest': 'false'}))
        print('Created release: ' + release['html_url'], flush=True)
        sums = stage / 'SHA256SUMS'
        sums.write_text(checksums, encoding='ascii')
        verified = {}
        for asset in [*args.asset, sums]:
            upload = release['upload_url'].split('{', 1)[0] + '?' + urlencode({'name': asset.name})
            info = json.loads(curl(upload, 'POST', file=asset))
            downloaded = curl(info['url'], accept='application/octet-stream')
            actual = hashlib.sha256(downloaded).hexdigest()
            if actual != digest(asset):
                raise RuntimeError('Downloaded checksum mismatch: ' + asset.name)
            verified[asset.name] = actual
        report = {'release_url': release['html_url'], 'commit': args.commit,
                  'verified_sha256': verified}
        (args.repo / 'release-published.json').write_text(json.dumps(report, indent=2) + '\n')
        print(json.dumps(report, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (OSError, RuntimeError, ValueError) as error:
        raise SystemExit(str(error))
