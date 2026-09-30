"""Exercise the strict retail byte-run guard on synthetic, asset-free data."""
import importlib.util
import io
import json
import random
import tarfile
import tempfile
import unittest
import zipfile
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path

SCRIPT = Path(__file__).resolve().parents[1] / 'tools/retail_byte_guard.py'
spec = importlib.util.spec_from_file_location('retail_byte_guard', SCRIPT)
guard = importlib.util.module_from_spec(spec)
spec.loader.exec_module(guard)


class RetailByteGuardTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        root = Path(self.tmp.name)
        rng = random.Random(1993)
        self.data = root / 'data'
        self.data.mkdir()
        self.exe = bytes(rng.randrange(256) for _ in range(8192))
        self.ovl = bytes(rng.randrange(256) for _ in range(8192)) + bytes(512)
        (self.data / 'XANTH.EXE').write_bytes(self.exe)
        (self.data / 'XANTH.OVL').write_bytes(self.ovl)
        (self.data / 'XANTH_02.PIC').write_bytes(bytes(rng.randrange(256) for _ in range(4096)))
        self.tree = root / 'tree'
        self.tree.mkdir()
        self.rng = rng

    def tearDown(self):
        self.tmp.cleanup()

    def noise(self, n):
        return bytes(self.rng.randrange(256) for _ in range(n))

    def scan(self, *targets):
        out, err = io.StringIO(), io.StringIO()
        report = Path(self.tmp.name) / 'runs.json'
        with redirect_stdout(out), redirect_stderr(err):
            code = guard.main(['--data', str(self.data), '--json', str(report),
                               *[str(t) for t in targets]])
        runs = json.loads(report.read_text()) if report.exists() else []
        return code, runs, out.getvalue() + err.getvalue()

    def test_clean_tree_passes(self):
        (self.tree / 'a.bin').write_bytes(self.noise(5000))
        code, runs, log = self.scan(self.tree)
        self.assertEqual(code, 0, log)
        self.assertEqual([r for r in runs if not r['trivial']], [])

    def test_32_byte_run_at_any_alignment_fails(self):
        for start in (0, 1, 7, 15, 16, 4001, 8192 - 32):
            with self.subTest(start=start):
                (self.tree / 'a.bin').write_bytes(
                    self.noise(100) + self.exe[start:start + 32] + self.noise(100))
                code, runs, log = self.scan(self.tree)
                self.assertEqual(code, 1, log)
                real = [r for r in runs if not r['trivial']]
                self.assertEqual(len(real), 1)
                self.assertEqual(real[0]['ref'], 'XANTH.EXE')
                self.assertEqual(real[0]['ref_offset'], start)
                self.assertEqual(real[0]['offset'], 100)
                self.assertGreaterEqual(real[0]['bytes'], 32)

    def test_31_byte_run_is_below_threshold(self):
        (self.tree / 'a.bin').write_bytes(self.noise(64) + self.ovl[1000:1031] + self.noise(64))
        code, runs, log = self.scan(self.tree)
        self.assertEqual(code, 0, log)

    def test_exact_length_reported(self):
        (self.tree / 'a.bin').write_bytes(b'\x00' * 3 + self.ovl[333:333 + 777] + b'\xff' * 3)
        code, runs, log = self.scan(self.tree)
        self.assertEqual(code, 1)
        real = [r for r in runs if not r['trivial']]
        self.assertEqual((real[0]['offset'], real[0]['ref_offset']), (3, 333))
        self.assertGreaterEqual(real[0]['bytes'], 777)
        self.assertLessEqual(real[0]['bytes'], 777 + 3)

    def test_fill_runs_are_trivial(self):
        (self.tree / 'a.bin').write_bytes(self.noise(40) + bytes(300) + self.noise(40))
        code, runs, log = self.scan(self.tree)
        self.assertEqual(code, 0, log)
        self.assertTrue(runs and all(r['trivial'] for r in runs))

    def test_archive_members_are_scanned(self):
        payload = self.noise(50) + self.exe[2000:2100] + self.noise(50)
        with zipfile.ZipFile(self.tree / 'pkg.zip', 'w', zipfile.ZIP_DEFLATED) as z:
            z.writestr('bin/xanth_port', payload)
        with tarfile.open(self.tree / 'pkg.tar.gz', 'w:gz') as t:
            info = tarfile.TarInfo('share/blob')
            info.size = len(payload)
            t.addfile(info, io.BytesIO(payload))
        code, runs, log = self.scan(self.tree)
        self.assertEqual(code, 1, log)
        labels = {r['target'].split('!')[-1] for r in runs if not r['trivial']}
        # Members are always found; a container that stores them verbatim is too.
        self.assertTrue({'bin/xanth_port', 'share/blob'} <= labels, labels)

    def test_symlinks_and_reference_copies_are_skipped(self):
        (self.tree / 'link.EXE').symlink_to(self.data / 'XANTH.EXE')
        (self.tree / 'ok.txt').write_bytes(b'hello world')
        code, runs, log = self.scan(self.tree, self.data / 'XANTH.OVL')
        self.assertEqual(code, 0, log)
        self.assertIn('symlink', log)
        self.assertIn('is reference data', log)

    def test_missing_data_is_a_config_error(self):
        (self.tree / 'a.bin').write_bytes(b'x' * 64)
        with redirect_stdout(io.StringIO()), redirect_stderr(io.StringIO()):
            code = guard.main(['--data', str(self.tree), str(self.tree)])
        self.assertEqual(code, 2)


if __name__ == '__main__':
    unittest.main()
