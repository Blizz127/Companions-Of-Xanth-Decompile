"""Read retail VGA screenshots with the game's own bitmap font."""

from __future__ import annotations

import struct
from pathlib import Path


def read_game_font_text(
    bitmap_path: Path,
    font_path: Path,
    y_start: int,
    y_end: int,
    *,
    channel_thresholds: tuple[int, int, int] = (210, 210, 210),
    x_start: int = 40,
) -> str:
    """Match panel pixels to the game's 8x8 glyphs using the stdlib only."""
    bitmap = bitmap_path.read_bytes()
    if bitmap[:2] != b"BM":
        raise ValueError(f"not a BMP: {bitmap_path}")
    offset = struct.unpack_from("<I", bitmap, 10)[0]
    width, signed_height = struct.unpack_from("<ii", bitmap, 18)
    bpp = struct.unpack_from("<H", bitmap, 28)[0]
    if width <= 0 or signed_height <= 0 or bpp != 24:
        raise ValueError(f"unsupported screenshot BMP format: {bitmap_path}")
    height = signed_height
    stride = (width * 3 + 3) & ~3
    mask = [[0] * width for _ in range(height)]
    r_min, g_min, b_min = channel_thresholds
    for y in range(height):
        row = offset + (height - 1 - y) * stride
        for x in range(width):
            blue, green, red = bitmap[row + x * 3:row + x * 3 + 3]
            mask[y][x] = int(red > r_min and green > g_min and blue > b_min)

    font = font_path.read_bytes()
    widths = list(font[43:43 + 95])
    glyphs = {}
    for code in range(0x21, 0x7F):
        pos = 138 + (code - 0x21) * 8
        raw = font[pos:pos + 8]
        glyphs[chr(code)] = (
            [[(byte >> (7 - bit)) & 1 for bit in range(8)] for byte in raw],
            widths[code - 0x21],
        )

    def line(y: int) -> str:
        x, output, guard = x_start, [], 0
        while x < 300 and guard < 400:
            guard += 1
            if sum(sum(mask[yy][x:x + 2]) for yy in range(y, y + 6)) == 0:
                blanks = 0
                while x < 300 and sum(mask[yy][x] for yy in range(y, y + 6)) == 0:
                    x += 1
                    blanks += 1
                    if blanks > 30:
                        break
                if blanks >= 2 and (not output or output[-1] != " "):
                    output.append(" ")
                continue
            best, best_score = None, -999
            for char, (glyph, glyph_width) in glyphs.items():
                glyph_width = max(glyph_width, 1)
                if x + glyph_width > width or y + 8 > height:
                    continue
                score = 0
                for yy in range(8):
                    for xx in range(glyph_width):
                        bit, pixel = glyph[yy][xx], mask[y + yy][x + xx]
                        score += bit * pixel * 2 - bit * (1 - pixel) * 3
                        score -= (1 - bit) * pixel * 2
                if score > best_score:
                    best, best_score = (char, glyph_width), score
            if best is None or best_score < 4:
                x += 1
                continue
            output.append(best[0])
            x += best[1]
        return "".join(output)

    lines = []
    for y in range(max(y_start, 0), min(y_end, height)):
        if sum(mask[y][x_start:280]) > 12:
            text = line(y).strip()
            if len(text) > 8:
                lines.append(text)
    return " ".join(lines)
