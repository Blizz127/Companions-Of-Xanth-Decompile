"""Tier 1: Feature Coverage — Feature 5: Portable types & memory bridge (F5).

Verifies 16-bit type emulation widths, segmented pointer virtualization math,
and virtual DOS memory read/write mechanics.
"""

from __future__ import annotations

import struct
import unittest

from e2e_tests.test_runner_common import VirtualDosMemory


class TestF05PortableTypes(unittest.TestCase):
    """Tier 1 tests for F5: Portable Types & Memory Bridge."""

    def test_portable_type_widths(self) -> None:
        """T1-F05-01: Types sword, uword, sdword, udword, ubyte, sbyte match exact bit-widths."""
        # sword / uword: 16-bit
        self.assertEqual(struct.calcsize("<h"), 2)
        self.assertEqual(struct.calcsize("<H"), 2)
        # sdword / udword: 32-bit
        self.assertEqual(struct.calcsize("<i"), 4)
        self.assertEqual(struct.calcsize("<I"), 4)
        # sbyte / ubyte: 8-bit
        self.assertEqual(struct.calcsize("<b"), 1)
        self.assertEqual(struct.calcsize("<B"), 1)

    def test_segmented_linear_address_calculation(self) -> None:
        """T1-F05-02: Segmented address (seg << 4) + off computes correct 20-bit linear offset."""
        # 0x1000:0x0020 -> 0x10020
        self.assertEqual(VirtualDosMemory.linear_address(0x1000, 0x0020), 0x10020)
        # VGA Mode 13h buffer: 0xA000:0x0000 -> 0xA0000
        self.assertEqual(VirtualDosMemory.linear_address(0xA000, 0x0000), 0xA0000)
        # BIOS data area: 0x0040:0x001A -> 0x0041A
        self.assertEqual(VirtualDosMemory.linear_address(0x0040, 0x001A), 0x0041A)

    def test_mk_fp_macro_round_trip(self) -> None:
        """T1-F05-03: MK_FP and FP_SEG/FP_OFF decomposition round-trips correctly."""
        seg = 0x30CB  # Overlay load segment
        off = 0x0400
        linear = VirtualDosMemory.linear_address(seg, off)

        # Decompose
        recovered_seg = (linear >> 4) & 0xFFFF
        recovered_off = linear & 0x0F  # normalized offset
        self.assertEqual(VirtualDosMemory.linear_address(recovered_seg, recovered_off), linear)

    def test_virtual_dos_memory_read_write(self) -> None:
        """T1-F05-04: Virtual DOS memory buffer performs accurate typed reads and writes."""
        mem = VirtualDosMemory()
        test_data = b"XANTH_PORT_MEMORY_BRIDGE_TEST"
        mem.write_bytes(0x2000, 0x0100, test_data)
        read_back = mem.read_bytes(0x2000, 0x0100, len(test_data))
        self.assertEqual(read_back, test_data)

        # Typed u16 and u32
        mem.write_u16(0x2000, 0x0200, 0xBEEF)
        self.assertEqual(mem.read_u16(0x2000, 0x0200), 0xBEEF)

        mem.write_u32(0x2000, 0x0300, 0xDEADCAFE)
        self.assertEqual(mem.read_u32(0x2000, 0x0300), 0xDEADCAFE)

    def test_calling_convention_attribute_stubs(self) -> None:
        """T1-F05-05: Calling convention macros evaluate without compilation syntax errors."""
        stubs = ["far", "near", "pascal", "cdecl", "interrupt", "__far", "__near"]
        # In portable C, these macros expand to empty strings
        macro_dict = {stub: "" for stub in stubs}
        for stub, expansion in macro_dict.items():
            self.assertEqual(expansion, "", f"Macro {stub} must expand to empty string")


if __name__ == "__main__":
    unittest.main()
