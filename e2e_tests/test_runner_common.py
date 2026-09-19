"""Shared fixtures, models, and test helpers for Companions of Xanth E2E Test Suite."""

from __future__ import annotations

import configparser
import hashlib
import json
import os
import struct
import tempfile
import zlib
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

ROOT = Path(__file__).resolve().parents[1]


def load_target_json() -> Dict[str, Any]:
    """Load config/target.json."""
    path = ROOT / "config/target.json"
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def load_c_units_json() -> Dict[str, Any]:
    """Load config/c-units.json."""
    path = ROOT / "config/c-units.json"
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def load_indexed_units() -> List[Dict[str, Any]]:
    """Load enriched units index via tools.units.index."""
    import sys
    tools_dir = str(ROOT / "tools")
    if tools_dir not in sys.path:
        sys.path.insert(0, tools_dir)
    from tools import units
    return units.index(ROOT)


class VirtualDosMemory:
    """1 MB Virtual DOS conventional memory model for segmented pointer testing."""

    MEM_SIZE = 1024 * 1024  # 1 MB

    def __init__(self) -> None:
        self.buffer = bytearray(self.MEM_SIZE)

    @staticmethod
    def linear_address(seg: int, off: int) -> int:
        return ((seg & 0xFFFF) << 4) + (off & 0xFFFF)

    def read_bytes(self, seg: int, off: int, length: int) -> bytes:
        addr = self.linear_address(seg, off)
        if addr + length > self.MEM_SIZE:
            raise ValueError(f"Memory read out of bounds: 0x{addr:X} + {length} > 0x{self.MEM_SIZE:X}")
        return bytes(self.buffer[addr : addr + length])

    def write_bytes(self, seg: int, off: int, data: bytes) -> None:
        addr = self.linear_address(seg, off)
        if addr + len(data) > self.MEM_SIZE:
            raise ValueError(f"Memory write out of bounds: 0x{addr:X} + {len(data)} > 0x{self.MEM_SIZE:X}")
        self.buffer[addr : addr + len(data)] = data

    def read_u16(self, seg: int, off: int) -> int:
        return struct.unpack("<H", self.read_bytes(seg, off, 2))[0]

    def write_u16(self, seg: int, off: int, val: int) -> None:
        self.write_bytes(seg, off, struct.pack("<H", val & 0xFFFF))

    def read_u32(self, seg: int, off: int) -> int:
        return struct.unpack("<I", self.read_bytes(seg, off, 4))[0]

    def write_u32(self, seg: int, off: int, val: int) -> None:
        self.write_bytes(seg, off, struct.pack("<I", val & 0xFFFFFFFF))


class VgaMode13h:
    """Mode 13h (320x200 8bpp) video subsystem reference model."""

    WIDTH = 320
    HEIGHT = 200
    FRAME_SIZE = WIDTH * HEIGHT  # 64,000 bytes

    def __init__(self) -> None:
        self.screen_buffer = bytearray(self.FRAME_SIZE)  # Segment 0xA000
        self.back_buffer = bytearray(self.FRAME_SIZE)    # Segment mn42E4
        self.active_buffer_id = 0                        # 0: screen, 1: back
        self.palette_dac = [(0, 0, 0)] * 256            # 6-bit RGB tuples
        self.palette_rgba = [(0, 0, 0, 255)] * 256      # 8-bit RGBA tuples

    def set_palette_entry(self, index: int, r: int, g: int, b: int) -> None:
        """Sets 6-bit DAC register and updates 8-bit RGBA lookup."""
        if not (0 <= index <= 255):
            raise IndexError(f"Palette index {index} out of range (0-255)")
        r6, g6, b6 = r & 0x3F, g & 0x3F, b & 0x3F
        self.palette_dac[index] = (r6, g6, b6)
        r8 = (r6 << 2) | (r6 >> 4)
        g8 = (g6 << 2) | (g6 >> 4)
        b8 = (b6 << 2) | (b6 >> 4)
        self.palette_rgba[index] = (r8, g8, b8, 255)

    def set_palette_bulk(self, start: int, rgb_triplets: bytes) -> int:
        """Writes bulk RGB triplets (3 bytes per index) starting at start."""
        count = len(rgb_triplets) // 3
        for i in range(count):
            idx = start + i
            if idx > 255:
                break
            r, g, b = rgb_triplets[i * 3 : i * 3 + 3]
            self.set_palette_entry(idx, r, g, b)
        return min(count, 256 - start)

    def blit_dirty_rect(self, x: int, y: int, w: int, h: int, src: bytes, stride: int) -> Tuple[int, int, int, int]:
        """Blits rectangle from src buffer into screen buffer with boundary clipping."""
        # Calculate clipped bounding box
        x0 = max(0, min(x, self.WIDTH))
        y0 = max(0, min(y, self.HEIGHT))
        x1 = max(0, min(x + w, self.WIDTH))
        y1 = max(0, min(y + h, self.HEIGHT))

        clip_w = x1 - x0
        clip_h = y1 - y0
        if clip_w <= 0 or clip_h <= 0:
            return (0, 0, 0, 0)

        src_offset_x = x0 - x
        src_offset_y = y0 - y

        for row in range(clip_h):
            dst_idx = (y0 + row) * self.WIDTH + x0
            src_idx = (src_offset_y + row) * stride + src_offset_x
            self.screen_buffer[dst_idx : dst_idx + clip_w] = src[src_idx : src_idx + clip_w]

        return (x0, y0, clip_w, clip_h)

    def flip_backbuffer(self) -> None:
        """Copies backbuffer (mn42E4) to screen buffer (0xA000)."""
        self.screen_buffer[:] = self.back_buffer[:]


class RealSoundDecoder:
    """Steve Baker RealSound 4-bit ADPCM decoder reference model."""

    MAGIC = b"STEVE\x02"

    @classmethod
    def parse_header(cls, data: bytes) -> Dict[str, Any]:
        if len(data) < 10 or not data.startswith(cls.MAGIC):
            raise ValueError(f"Invalid RealSound header: expected {cls.MAGIC}, got {data[:6]}")
        sample_rate, num_samples = struct.unpack("<HH", data[6:10])
        return {
            "magic": cls.MAGIC,
            "sample_rate": sample_rate,
            "num_samples": num_samples,
            "data_offset": 10,
        }

    @classmethod
    def decode_adpcm_nibbles(cls, adpcm_data: bytes, expected_samples: int) -> List[int]:
        """Decodes 4-bit nibbles into 8-bit PCM samples."""
        pcm = []
        if expected_samples <= 0:
            return pcm
        val = 128
        for byte in adpcm_data:
            low_nibble = byte & 0x0F
            val = max(0, min(255, val + (low_nibble - 8) * 8))
            pcm.append(val)
            if len(pcm) >= expected_samples:
                break
            high_nibble = (byte >> 4) & 0x0F
            val = max(0, min(255, val + (high_nibble - 8) * 8))
            pcm.append(val)
            if len(pcm) >= expected_samples:
                break
        return pcm


class VocArchiveParser:
    """XANTH_01.VOC speech archive parser reference model."""

    @classmethod
    def parse_archive_header(cls, header_bytes: bytes) -> List[Tuple[int, int]]:
        """Parses {offset, length} records from archive header."""
        if len(header_bytes) < 2:
            raise ValueError("Header too short")
        count = struct.unpack("<H", header_bytes[:2])[0]
        entries = []
        pos = 2
        for _ in range(count):
            if pos + 8 > len(header_bytes):
                break
            offset, length = struct.unpack("<II", header_bytes[pos : pos + 8])
            entries.append((offset, length))
            pos += 8
        return entries


class Opl3PortEmulation:
    """Nuked OPL3 port interface tracking."""

    def __init__(self) -> None:
        self.active_reg = 0
        self.registers = [0] * 512

    def write_port(self, port: int, val: int) -> None:
        if port in (0x388, 0x228):  # AdLib / Sound Blaster primary register port
            self.active_reg = val & 0x1FF
        elif port in (0x389, 0x229):  # Primary data port
            if self.active_reg < 512:
                self.registers[self.active_reg] = val & 0xFF


class MouseInt33h:
    """INT 33h Mouse driver reference model (640x200 virtual -> 320x200 logical)."""

    def __init__(self) -> None:
        self.virt_x = 0  # 0..639
        self.virt_y = 0  # 0..199
        self.buttons = 0  # bit 0: left, bit 1: right

    def set_screen_coords(self, x: int, y: int, left: bool, right: bool) -> None:
        cx = max(0, min(x, 319))
        cy = max(0, min(y, 199))
        self.virt_x = cx * 2
        self.virt_y = cy
        self.buttons = (1 if left else 0) | (2 if right else 0)

    def get_screen_coords(self) -> Tuple[int, int, int]:
        x = self.virt_x >> 1
        y = self.virt_y
        return (x, y, self.buttons)


class KeyboardInt16h:
    """INT 16h BIOS keyboard buffer ring model."""

    CAPACITY = 16

    def __init__(self) -> None:
        self.queue: List[Tuple[int, int]] = []  # (scancode, ascii)
        self.shift_flags = 0

    def push_key(self, scancode: int, ascii_char: int) -> bool:
        if len(self.queue) >= self.CAPACITY:
            return False
        self.queue.append((scancode & 0xFF, ascii_char & 0xFF))
        return True

    def poll_key(self) -> Optional[Tuple[int, int]]:
        if not self.queue:
            return None
        return self.queue[0]

    def read_key(self) -> Optional[Tuple[int, int]]:
        if not self.queue:
            return None
        return self.queue.pop(0)


class LegendIniParser:
    """Parser for LEGEND.INI configuration files."""

    @classmethod
    def parse_ini(cls, text: str) -> Dict[str, str]:
        res = {}
        for line in text.splitlines():
            line = line.strip()
            if not line or line.startswith(";") or line.startswith("#"):
                continue
            if "=" in line:
                k, v = line.split("=", 1)
                res[k.strip().upper()] = v.strip()
        return res


class SavegameState:
    """Savegame serialization data model."""

    MAGIC = b"XSAV"
    VERSION = 1

    def __init__(self, slot: int, room_id: int, inventory: List[int], flags: Dict[str, int]) -> None:
        self.slot = slot
        self.room_id = room_id
        self.inventory = list(inventory)
        self.flags = dict(flags)

    def serialize(self) -> bytes:
        payload = json.dumps({
            "slot": self.slot,
            "room_id": self.room_id,
            "inventory": self.inventory,
            "flags": self.flags,
        }).encode("utf-8")
        crc = zlib.crc32(payload)
        header = struct.pack("<4sHII", self.MAGIC, self.VERSION, len(payload), crc)
        return header + payload

    @classmethod
    def deserialize(cls, data: bytes) -> SavegameState:
        if len(data) < 14:
            raise ValueError("Save file truncated")
        magic, ver, length, crc = struct.unpack("<4sHII", data[:14])
        if magic != cls.MAGIC:
            raise ValueError(f"Invalid save magic: {magic}")
        if ver != cls.VERSION:
            raise ValueError(f"Unsupported save version: {ver}")
        payload = data[14 : 14 + length]
        if len(payload) != length:
            raise ValueError("Corrupted save payload length")
        if zlib.crc32(payload) != crc:
            raise ValueError("Save file CRC32 checksum mismatch")
        doc = json.loads(payload.decode("utf-8"))
        return cls(doc["slot"], doc["room_id"], doc["inventory"], doc["flags"])


class CaseInsensitiveResolver:
    """Case-insensitive path resolver for Linux and Windows."""

    @staticmethod
    def resolve_path(base: Path, relative: str) -> Optional[Path]:
        parts = relative.replace("\\", "/").strip("/").split("/")
        current = base
        for part in parts:
            if not part or part == ".":
                continue
            if part == "..":
                parent = current.parent
                base_res = base.resolve()
                parent_res = parent.resolve()
                if parent_res != base_res and base_res not in parent_res.parents:
                    return None
                current = parent
                continue
            if not current.is_dir():
                return None
            found = False
            for child in current.iterdir():
                if child.name.lower() == part.lower():
                    current = child
                    found = True
                    break
            if not found:
                return None
        return current
