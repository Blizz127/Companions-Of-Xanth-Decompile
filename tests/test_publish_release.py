"""Exercise release ordering, credential handling and download verification offline."""
import importlib.util
import json
import io
from contextlib import redirect_stdout
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SCRIPT = Path(__file__).resolve().parents[1] / 'scripts/publish_release.py'
spec = importlib.util.spec_from_file_location('publisher', SCRIPT)
publisher = importlib.util.module_from_spec(spec)
spec.loader.exec_module(publisher)
COMMIT = 'a' * 40


class PublishingTests(unittest.TestCase):
    def exercise(self, corrupt=False, offline=False):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            asset = root / 'port.tar.gz'; asset.write_bytes(b'tested executable fixture')
            notes = root / 'notes.md'; notes.write_text('Experimental release')
            token = root / 'private-token'
            if not offline:
                token.write_text('test_token_NEVER_IN_ARGV')
            calls, uploads = [], {}
            def fake_run(argv, **kwargs):
                calls.append((argv, kwargs))
                self.assertNotIn('test_token_NEVER_IN_ARGV', repr(argv))
                self.assertNotIn('test_token_NEVER_IN_ARGV', repr(kwargs.get('env', {})))
                if argv[0] == 'git':
                    if 'rev-parse' in argv:
                        return COMMIT.encode()
                    if 'ls-remote' in argv:
                        if 'refs/heads/release/test' in argv:
                            return (COMMIT + '\trefs/heads/release/test').encode()
                    return b''
                if offline:
                    raise RuntimeError('curl failed (exit 6)')
                if '--config' not in argv: return b'{}'
                url = argv[argv.index('--request') + 2]
                if url.endswith('per_page=100'): return b'[]'
                if url.endswith('/releases'):
                    self.assertTrue(any('push' in c[0] for c in calls))
                    return json.dumps({'html_url': 'https://github.com/example/release',
                                       'upload_url': 'https://uploads.github.com/release{?name,label}'}).encode()
                if url.startswith('https://uploads.github.com/'):
                    file = Path(argv[argv.index('--data-binary') + 1][1:])
                    download = 'https://api.github.com/assets/' + file.name
                    uploads[download] = file.read_bytes()
                    return json.dumps({'url': download}).encode()
                return b'corrupt' if corrupt else uploads[url]
            args = ['publish_release.py', '--repo', str(root), '--branch', 'release/test',
                    '--tag', 'test', '--commit', COMMIT, '--notes', str(notes), '--asset', str(asset)]
            with redirect_stdout(io.StringIO()), patch.object(publisher, 'TOKEN', token), patch.object(publisher, 'run', fake_run), patch('sys.argv', args):
                if offline or corrupt:
                    with self.assertRaisesRegex(RuntimeError, 'curl failed|checksum mismatch'):
                        publisher.main()
                    self.assertFalse((root / 'release-published.json').exists())
                else:
                    publisher.main()
                    report = json.loads((root / 'release-published.json').read_text())
                    self.assertEqual(report['commit'], COMMIT)
                    self.assertEqual(report['verified_sha256'][asset.name], publisher.digest(asset))
                    self.assertIn('SHA256SUMS', report['verified_sha256'])
            if offline:
                self.assertFalse(any('push' in argv for argv, _ in calls))
            else:
                self.assertNotIn('--force', repr(calls))
                self.assertEqual(len(uploads), 1 if corrupt else 2)

    def test_publish_and_verify(self): self.exercise()
    def test_corrupt_download_fails(self): self.exercise(corrupt=True)
    def test_offline_reads_no_token_and_makes_no_push(self): self.exercise(offline=True)


if __name__ == '__main__': unittest.main()
