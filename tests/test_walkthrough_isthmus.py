"""Walkthrough segment 8: Isthmus Village through the trapped bucket.

Starts from the prebuilt village-center anchor (45 points, Nada Naga)
rather than replaying segment 7, which another trace owns. The route
then agrees to help the headman, opens the gate, recovers the anchor,
pries a log, has it planed into a board, and springs the catapult so
the rock traps the runaway bucket. The score screen at the end reads
102 of 1000.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import re
import shutil
import subprocess
import unittest
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
EXE = PROJECT_ROOT / "original" / "XANTH.EXE"
DATA = PROJECT_ROOT / "game_cd" / "XANTH"
TOOL = PROJECT_ROOT / "build" / "tool_vmboot"
TRACE = PROJECT_ROOT / "tests" / "traces" / "walkthrough_08_from_village.xit"
ANCHOR_SOURCE = PROJECT_ROOT / "build" / "anchor_xanth"
ANCHOR_TRACE = PROJECT_ROOT / "tests" / "traces" / "make_anchor_isthmus_village.xit"
ANCHOR = PROJECT_ROOT / "build" / "anchor_isthmus_village"
SAVES = PROJECT_ROOT / "build" / "agent_isthmus" / "segment"
SCORE = PROJECT_ROOT / "build" / "frames" / "wt8_score.bmp"

# Measured: the trace executes 6.972e9 instructions. A short budget
# truncates silently and the later checkpoints never appear.
BUDGET = 9_000_000_000

# Checkpoint order is the order the trace reaches them. Two consecutive
# runs produced these hashes; they are pinned, not guessed.
ORDER = [
    "wt8_resumed",
    "wt8_key",
    "wt8_gate",
    "wt8_rock",
    "wt8_covers",
    "wt8_pier",
    "wt8_sail",
    "wt8_anchor",
    "wt8_hook",
    "wt8_crossroads",
    "wt8_log",
    "wt8_board",
    "wt8_cliffs",
    "wt8_board_set",
    "wt8_rock_set",
    "wt8_sprung",
    "wt8_bucket",
    "wt8_score",
]

GOLDEN = {
    "wt8_resumed":    "cad0d6ea9292112c",
    "wt8_key":        "1c7d2b0d23da592a",
    "wt8_gate":       "4d8a6566416d09dd",
    "wt8_rock":       "d3516d48e189fb23",
    "wt8_covers":     "6f0bcbea0c112dcb",
    "wt8_pier":       "2da78edd5a49d9a2",
    "wt8_sail":       "b90ea90468e58315",
    "wt8_anchor":     "c16a9f042cc7c669",
    "wt8_hook":       "bcf516465b378c67",
    "wt8_crossroads": "53bc7bee614ad904",
    "wt8_log":        "ac110aaa149cb52c",
    "wt8_board":      "e223e3b14239bb0d",
    "wt8_cliffs":     "6fabe674b7b4b243",
    "wt8_board_set":  "3392e761ce887a48",
    "wt8_rock_set":   "db14cdddc1d6e257",
    "wt8_sprung":     "47c284c7b93c66ee",
    "wt8_bucket":     "a2893f6c75c18859",
    "wt8_score":      "5693e2349f51fc3a",
}


def _score_text(path: Path) -> str:
    """Read the status panel with the game's own UI font (XANTH_10.FNT)."""
    import struct

    bitmap = path.read_bytes()
    if bitmap[:2] != b"BM":
        raise ValueError(f"not a BMP: {path}")
    pixels_offset = struct.unpack_from("<I", bitmap, 10)[0]
    width, signed_height = struct.unpack_from("<ii", bitmap, 18)
    bits_per_pixel = struct.unpack_from("<H", bitmap, 28)[0]
    if width <= 0 or signed_height <= 0 or bits_per_pixel != 24:
        raise ValueError(f"unsupported score BMP format: {path}")
    height = signed_height
    stride = (width * 3 + 3) & ~3
    mask = [[0] * width for _ in range(height)]
    for y in range(height):
        row = pixels_offset + (height - 1 - y) * stride
        for x in range(width):
            blue, green, red = bitmap[row + x * 3:row + x * 3 + 3]
            mask[y][x] = int(red > 210 and green > 210 and blue > 210)

    data = (DATA / "XANTH_10.FNT").read_bytes()
    widths = list(data[43:43 + 95])
    glyphs = {}
    for ch in range(0x21, 0x7F):
        off = 138 + (ch - 0x21) * 8
        raw = data[off:off + 8]
        glyphs[chr(ch)] = ([[(b >> (7 - k)) & 1 for k in range(8)]
                            for b in raw], widths[ch - 0x21])

    def line(y: int) -> str:
        x = 40
        out: list[str] = []
        guard = 0
        while x < 300 and guard < 400:
            guard += 1
            if sum(sum(mask[yy][x:x + 2]) for yy in range(y, y + 6)) == 0:
                n = 0
                while x < 300 and sum(mask[yy][x] for yy in range(y, y + 6)) == 0:
                    x += 1
                    n += 1
                    if n > 30:
                        break
                if n >= 2 and (not out or out[-1] != " "):
                    out.append(" ")
                continue
            best, bests = None, -999
            for ch, (rows, gw) in glyphs.items():
                gw = max(gw, 1)
                if x + gw > width or y + 8 > height:
                    continue
                score = 0
                for yy in range(8):
                    for xx in range(gw):
                        bit = rows[yy][xx]
                        pixel = mask[y + yy][x + xx]
                        score += bit * pixel * 2 - bit * (1 - pixel) * 3
                        score -= (1 - bit) * pixel * 2
                if score > bests:
                    best, bests = (ch, gw), score
            if best is None or bests < 4:
                x += 1
                continue
            out.append(best[0])
            x += best[1]
        return "".join(out)

    lines = []
    for y in range(40, 90):
        if sum(mask[y][40:280]) > 12:
            text = line(y).strip()
            if len(text) > 8:
                lines.append(text)
    return " ".join(lines)


class IsthmusVillageTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "walkthrough trace"),
                           (ANCHOR_TRACE, "village anchor trace"),
                           (ANCHOR_SOURCE / "XANTH000.SAV", "cavern anchor save")):
            if not path.exists():
                raise unittest.SkipTest(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unittest.SkipTest(f"{TOOL} not built")

        # The similarly named local anchor_isthmus is also used by a later
        # segment and is the 193-point Void save. Build this test's village
        # anchor independently from the 40-point cavern seed so the fixtures
        # cannot overwrite or silently reuse one another.
        if ANCHOR.exists():
            shutil.rmtree(ANCHOR)
        shutil.copytree(ANCHOR_SOURCE, ANCHOR)
        anchor_proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(ANCHOR), "--script", str(ANCHOR_TRACE),
             "--insns", "6000000000"],
            capture_output=True, text=True, timeout=900,
        )
        anchor_out = anchor_proc.stdout + anchor_proc.stderr
        if (anchor_proc.returncode != 0
                or "fault                 : ok" not in anchor_out
                or "MCB chain valid       : yes" not in anchor_out
                or "wt8_village_anchor" not in anchor_out):
            raise AssertionError(
                f"could not build 45-point village anchor:\n{anchor_out[-2000:]}")

        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
        for name in ("LEGEND.INI", "RESTART.DAT", "XANTH000.SAV"):
            shutil.copy(ANCHOR / name, SAVES / name)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = {m.group(1): m.group(2) for m in
                     re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)",
                                 cls.out)}

    def test_segment_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_guest_heap_intact(self) -> None:
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_all_checkpoints_reached(self) -> None:
        for name in ORDER:
            self.assertIn(name, self.marks,
                          f"never reached {name} -- if the route is right, "
                          f"suspect BUDGET")

    def test_each_checkpoint_changes_the_world(self) -> None:
        for prev, name in zip(ORDER, ORDER[1:]):
            self.assertNotEqual(
                self.marks[prev], self.marks[name],
                f"{name} is the same frame as {prev}")

    def test_matches_golden_frames(self) -> None:
        for name, want in GOLDEN.items():
            self.assertEqual(
                self.marks[name], want,
                f"{name} renders differently. If intended, inspect "
                f"build/frames/wt8_bucket.bmp and update deliberately -- "
                f"never just to make this pass.")

    def test_the_bucket_is_not_still_the_village(self) -> None:
        self.assertNotEqual(self.marks["wt8_bucket"],
                            self.marks["wt8_resumed"])
        self.assertNotEqual(self.marks["wt8_bucket"],
                            self.marks["wt8_sprung"],
                            "leaving the cliffs did not reach a new room")

    def test_score_is_one_hundred_two(self) -> None:
        """The status panel prints the total the published route awards
        through Nada springing the catapult: 102 of 1000."""
        self.assertTrue(SCORE.exists(), "the score frame was not written")
        text = _score_text(SCORE)
        self.assertIn("102", text, f"score panel did not show 102:\n{text}")
        self.assertIn("points", text,
                      f"score panel was not the status text:\n{text}")


if __name__ == "__main__":
    unittest.main()
