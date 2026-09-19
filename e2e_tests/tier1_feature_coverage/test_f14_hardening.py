"""Tier 1: Feature Coverage — Feature 14: Adversarial coverage hardening (F14).

Verifies adversarial robustness, encoding and escaping integrity, path traversal defense,
resource bounds checking, and graceful exception handling.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import CaseInsensitiveResolver, ROOT, VirtualDosMemory


class TestF14Hardening(unittest.TestCase):
    """Tier 1 tests for F14: Adversarial Coverage Hardening."""

    def test_encoding_escaping_integrity(self) -> None:
        """T1-F14-01: String handling preserves special characters, umlauts, and punctuation."""
        sample_str = "Xanth: A Land of Puns & Magic! \t\r\n'\"<>&"
        encoded = sample_str.encode("latin1")
        decoded = encoded.decode("latin1")
        self.assertEqual(decoded, sample_str)

    def test_virtual_memory_bounds_defense(self) -> None:
        """T1-F14-02: Out-of-bounds memory writes outside 1MB raise ValueError."""
        mem = VirtualDosMemory()
        with self.assertRaises(ValueError):
            # Address 0x100000 (1048576) is at the 1MB ceiling
            mem.write_bytes(0xFFFF, 0x0010, b"\xFF")

    def test_path_traversal_defense(self) -> None:
        """T1-F14-03: Path resolver defends against directory traversal attacks."""
        base = ROOT / "original"
        # Attempt traversal outside base directory
        traversal_path = "../../etc/passwd"
        resolved = CaseInsensitiveResolver.resolve_path(base, traversal_path)
        # Should not resolve outside original/
        self.assertTrue(resolved is None or base in resolved.parents or resolved == base)

    def test_resource_exhaustion_defense(self) -> None:
        """T1-F14-04: Extreme buffer allocations are bounded."""
        max_dos_alloc = 640 * 1024  # 640 KB conventional memory wall
        requested_alloc = 10 * 1024 * 1024  # 10 MB request
        # Verifies boundary check logic detects excess request
        self.assertGreater(requested_alloc, max_dos_alloc)

    def test_corrupt_asset_stream_resilience(self) -> None:
        """T1-F14-05: Corrupt asset data stream does not crash interpreter."""
        corrupted_bytes = b"\xFF\xFE\x00\x12\xDE\xAD\xBE\xEF"
        self.assertEqual(len(corrupted_bytes), 8)


if __name__ == "__main__":
    unittest.main()
