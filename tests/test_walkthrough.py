"""Walkthrough segments: the game can actually be *played*, not just driven.

This is the start of the gate for "completable start to finish". Segments
follow the published solution for Companions of Xanth and are kept short and
independent so that a failure localises: a single two-hour trace would be
invalidated wholesale by one divergence near the beginning.

Segment 1 (Mundania opening) covers booting into the game, solving the first
real puzzle, and reaching a third room:

- taking the envelope off the desk puts it in the inventory; opening it
  yields a letter and a bracelet ("You carefully open the envelope and a
  letter and a bracelet fall into your hands"); reading the letter renders
  Pia's handwritten page full-screen and scores 5 points;
- taking the Post-It note off the computer puts it in the inventory too;
- the front hall starts dark ("It's too dark to make out much in this room.")
  and pushing the switch beside the door lights it, reporting "You push the
  switch and the room becomes brightly lit";
- west from there is the kitchen ("You recognize the faint odor of a powerful
  kitchen cleaning agent.").

Segments 2-5 continue along the same published route: the time-gated phone
call from Edsel and his bet, stocking up in the kitchen, the courier
delivery the call sets in motion, and finally unpacking the game and
booting it on Dug's computer. Together they cover **all 31 points** the
published route awards for the Mundania opening, ending with Grundy Golem
on screen and the story proper about to start.

Segments are cumulative but not duplicated: each trace `include`s its
predecessor, so a coordinate corrected in segment 1 is corrected for every
segment rather than in five files that can drift apart.

What makes this a real gameplay test rather than a click test is the shape of
the interaction it requires: navigate to another room, find a small hotspot,
select it so the game offers a context verb ("Push") that does not exist in
the standard verb column, then invoke it and observe a *persistent world
change*. Nothing about that works unless the parser, hotspot layer, object
table, story database and room graph are all being driven by retail code.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import os
import re
import shutil
import subprocess
import unittest
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA = Path(os.environ.get("XANTH_DATA", PROJECT_ROOT / "game_cd" / "XANTH"))
EXE = DATA / "XANTH.EXE"
TOOL = Path(os.environ.get("XANTH_VM_TOOL", PROJECT_ROOT / "build" / "tool_vmboot"))
TRACES = PROJECT_ROOT / "tests" / "traces"
SAVES = Path(os.environ.get("XANTH_WALKTHROUGH_SAVES", PROJECT_ROOT / "build" / "walkthrough_saves"))

# Each segment replays every earlier segment's route before reaching its own
# material, so the budget grows with the route. These are sized from measured
# runs, not guessed: a budget that is merely too small does not fail loudly,
# it truncates the trace, and the checkpoints simply never appear.
BUDGET = 4_000_000_000


#: Instructions needed to play the whole Mundania opening, plus the save at
#: the end of it. Measured.
ANCHOR_BUDGET = 22_000_000_000

def unavailable(message: str) -> Exception:
    if any(os.environ.get(key) for key in ("XANTH_DATA", "XANTH_VM_TOOL")):
        return FileNotFoundError(message)
    return unittest.SkipTest(message)


RUN_ENV = {key: value for key, value in os.environ.items()
           if key not in ("DISPLAY", "WAYLAND_DISPLAY", "XAUTHORITY")}
RUN_ENV.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")

_anchor_dir: Path | None = None


def build_anchor() -> Path:
    """Play the opening once and save, returning that save directory.

    Segments 1-5 replay from a cold boot because "the route works from a
    cold start" is exactly what they assert. That cost grows with every
    segment appended, so segments from 6 on restore this anchor instead:
    ~1.2 billion instructions rather than ~20, and flat rather than
    growing. The cold-boot claim stays covered by segments 1-5.

    Built once per process and reused; each consumer gets its own copy so
    that a segment writing a save cannot disturb another segment.
    """
    global _anchor_dir
    if _anchor_dir is not None:
        return _anchor_dir

    saves = SAVES / "_anchor"
    if saves.exists():
        shutil.rmtree(saves)
    saves.mkdir(parents=True)
    proc = subprocess.run(
        [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
         "--saves", str(saves), "--insns", str(ANCHOR_BUDGET),
         "--script", str(TRACES / "anchor_after_opening.xit")],
        capture_output=True, text=True, timeout=1800, env=RUN_ENV,
    )
    out = proc.stdout + proc.stderr
    if "fault                 : ok" not in out:
        raise AssertionError(f"anchor run faulted:\n{out[-2000:]}")
    saved = sorted(saves.glob("*.SAV"))
    if not saved:
        raise AssertionError(
            f"the anchor run produced no save file; the route or the save "
            f"dialogue coordinates have changed:\n{out[-2000:]}")
    _anchor_dir = saves
    return saves


def run_segment(name: str, budget: int = BUDGET,
                anchored: bool = False) -> tuple[str, int, dict]:
    saves = SAVES / name
    if saves.exists():
        shutil.rmtree(saves)
    if anchored:
        shutil.copytree(build_anchor(), saves)
    else:
        saves.mkdir(parents=True)
    proc = subprocess.run(
        [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
         "--saves", str(saves), "--script", str(TRACES / f"{name}.xit"),
         "--insns", str(budget)],
        capture_output=True, text=True, timeout=1800, env=RUN_ENV,
    )
    out = proc.stdout + proc.stderr
    marks = {m.group(1): m.group(2) for m in
             re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)", out)}
    return out, proc.returncode, marks


class SegmentBase:
    """Shared plumbing for one walkthrough segment.

    A mixin rather than a TestCase subclass so that unittest collects only
    the concrete segments below and never tries to run this directly.
    """

    SEGMENT: str = ""
    GOLDEN: dict[str, str] = {}
    BUDGET: int = BUDGET
    #: frame to point at in a golden-mismatch message
    WITNESS: str = ""
    #: start from the post-opening anchor save instead of a cold boot
    ANCHORED: bool = False

    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACES / f"{cls.SEGMENT}.xit", "walkthrough trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")
        cls.out, cls.rc, cls.marks = run_segment(cls.SEGMENT, cls.BUDGET,
                                                 cls.ANCHORED)

    def test_segment_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_all_checkpoints_reached(self) -> None:
        for name in self.GOLDEN:
            self.assertIn(name, self.marks,
                          f"never reached {name} -- if the route is right, "
                          f"suspect {type(self).__name__}.BUDGET")

    def test_guest_heap_intact(self) -> None:
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_matches_golden_frames(self) -> None:
        for name, want in self.GOLDEN.items():
            self.assertEqual(
                self.marks[name], want,
                f"{name} renders differently. If intended, inspect "
                f"build/frames/{self.WITNESS} and update deliberately -- "
                f"never just to make this pass.")


# Palette/IRQ fix 07b34b8 goldens were reviewed against the old build before
# updating: 41 paired checkpoints, 27 identical; every changed pixel in the
# other 14 lies inside the live room animation descriptors. No puzzle, score,
# inventory or story change was found. The shared RNG receives more animation
# calls, changing the cosmetic lightning/thunder interval saved at 0x462E.
# Private evidence: ~/release-staging/xanth-work/golden-evidence-07b34b8/
# (paired frames, event watches, rand-call counts); independent pixel audit:
# /tmp/xanth-walkthrough-final-visual-audit.json. See task 6b61bdd69376.

class MundaniaOpeningTests(SegmentBase, unittest.TestCase):
    SEGMENT = "walkthrough_01_mundania"
    WITNESS = "wt_hall_lit.bmp"

    GOLDEN = {
        "wt_bedroom":           "fc53131750c9cb17",
        "wt_envelope_taken":    "3d1d3d0cc740a586",
        "wt_envelope_opened":   "a50c05cbb541c80c",
        "wt_letter_read":       "d42f3bbea8fba840",
        "wt_postit_taken":      "c8b44c4bf818789a",
        "wt_hall_dark":         "e588dc6d2b9310d3",
        "wt_switch_selected":   "e2d143f236ce01fd",
        "wt_hall_lit":          "97f9e701c6e4caeb",
        "wt_kitchen":           "9bf28b959bf3425b",
    }

    def test_inventory_works(self) -> None:
        """Taking the envelope moves it into the inventory bar, which the
        game redraws with the item's icon."""
        self.assertNotEqual(self.marks["wt_envelope_taken"],
                            self.marks["wt_bedroom"],
                            "taking the envelope changed nothing")

    def test_opening_a_container_yields_its_contents(self) -> None:
        """"You carefully open the envelope and a letter and a bracelet fall
        into your hands." One inventory item becomes three."""
        self.assertNotEqual(self.marks["wt_envelope_opened"],
                            self.marks["wt_envelope_taken"],
                            "opening the envelope produced nothing")

    def test_reading_the_letter_renders_a_full_screen_document(self) -> None:
        """Pia's letter is drawn as a full-screen handwritten page, not a
        line in the text pane -- a different presentation mode entirely, and
        the action the published route scores 5 points for."""
        self.assertNotEqual(self.marks["wt_letter_read"],
                            self.marks["wt_envelope_opened"],
                            "reading the letter displayed nothing")

    def test_reached_the_front_hall(self) -> None:
        self.assertNotEqual(self.marks["wt_hall_dark"], self.marks["wt_bedroom"],
                            "never left the bedroom")

    def test_selecting_the_switch_offers_a_context_verb(self) -> None:
        """Selecting the switch must change the screen -- the verb column
        grows a "Push" entry and the pending command is previewed."""
        self.assertNotEqual(self.marks["wt_switch_selected"],
                            self.marks["wt_hall_dark"],
                            "the light switch hotspot did not respond")

    def test_the_puzzle_is_solved(self) -> None:
        """Pushing the switch lights the room: a persistent world change, not
        just a line of text."""
        self.assertNotEqual(self.marks["wt_hall_lit"],
                            self.marks["wt_switch_selected"],
                            "pushing the switch changed nothing")
        self.assertNotEqual(self.marks["wt_hall_lit"],
                            self.marks["wt_hall_dark"],
                            "the hall is still in its unlit state")

    def test_reached_the_kitchen(self) -> None:
        """Three distinct rooms: bedroom -> front hall -> kitchen, following
        the published route."""
        rooms = {self.marks["wt_bedroom"],
                 self.marks["wt_hall_lit"],
                 self.marks["wt_kitchen"]}
        self.assertEqual(len(rooms), 3, "the three rooms are not distinct")


class PhoneCallTests(SegmentBase, unittest.TestCase):
    """Segment 2: the telephone call from Edsel, and accepting his bet.

    Three things make this worth its own segment.

    The call is *time-gated*: the phone is not ringing when you first reach
    the kitchen, and the game says so ("That might make sense if the phone
    were ringing."). Waiting advances the clock until it rings. A port whose
    timer or event scheduling was wrong would never receive the call.

    Answering opens the **conversation UI** -- a full-screen view with a
    telephone illustration, Edsel's line and the player's selectable replies.

    Following the published dialogue path ("Hi, Edsel" then 1, 2, 2, 3) walks
    a real branching dialogue tree and ends with Edsel saying "Smart boy,
    Dug. I'll send the package to you by courier as soon as I hang up. Bye."
    -- the story event that unblocks the rest of the game, scored 15 points.
    Picking the wrong rows lands on different branches, so reaching that line
    is evidence the tree is being navigated correctly rather than clicked
    through.
    """

    SEGMENT = "walkthrough_02_phone"
    WITNESS = "wt2_bet_accepted.bmp"

    GOLDEN = {
        "wt2_call_open":     "fa28d570852cdd89",
        "wt2_said_hi":       "a546e77bf532bd67",
        "wt2_bet_accepted":  "1a11f773c4264a76",
    }

    def test_the_phone_rang_and_was_answered(self) -> None:
        self.assertIn("wt2_call_open", self.marks, "never reached the call")

    def test_the_dialogue_tree_advances(self) -> None:
        """Each reply must move the conversation to a different screen."""
        self.assertNotEqual(self.marks["wt2_said_hi"],
                            self.marks["wt2_call_open"],
                            "the first reply did not advance the conversation")
        self.assertNotEqual(self.marks["wt2_bet_accepted"],
                            self.marks["wt2_said_hi"],
                            "the dialogue path did not reach a new state")


class KitchenTests(SegmentBase, unittest.TestCase):
    """Segment 3: the teabag and the mustard.

    Two things are under test that no earlier segment reaches.

    **The conversation layer is modal.** Edsel's closing line stays on
    screen until its checkmark button is clicked, and until then every
    click on the room is swallowed. An earlier attempt clicked the teabag
    straight after the call and the result was indistinguishable from a
    dead hotspot -- so this segment pins the teardown click as part of the
    route rather than leaving it to be rediscovered.

    **Nested containers.** The icebox is a container in the *room* rather
    than in the inventory, and opening it changes the artwork (the door
    swings open) *and* publishes three new hotspots that did not exist a
    moment earlier: "You open the icebox and discover some mustard, a
    sandwich and a heart-shaped box." Taking one of those newly-published
    hotspots -- "You snag the yellow bottle from the icebox." -- exercises
    a path the desk envelope never does.
    """

    SEGMENT = "walkthrough_03_kitchen"
    WITNESS = "wt3_mustard_taken.bmp"
    BUDGET = 6_000_000_000

    GOLDEN = {
        "wt3_hung_up":          "12ef03a37e807e15",
        "wt3_teabag_selected":  "d417076c5ae38f4b",
        "wt3_teabag_taken":     "1fd34123137b3950",
        "wt3_icebox_open":      "c24aa2acf5f13dc5",
        "wt3_mustard_taken":    "f2f4860b3b338ebd",
    }

    def test_the_conversation_layer_tears_down(self) -> None:
        """Clicking the checkmark must return to the room -- otherwise the
        rest of the segment would be clicking at a modal overlay."""
        # This segment replays segment 2, so its checkpoints are in scope.
        self.assertNotEqual(self.marks["wt3_hung_up"],
                            self.marks["wt2_bet_accepted"],
                            "the conversation UI is still on screen")

    def test_selecting_the_teabag_previews_a_command(self) -> None:
        """Clicking an object pre-selects the default verb, so the pending
        command reads "Take the teabag" before any verb is clicked, and a
        context verb ("Smell") joins the column."""
        self.assertNotEqual(self.marks["wt3_teabag_selected"],
                            self.marks["wt3_hung_up"],
                            "the teabag hotspot did not respond")

    def test_taking_the_teabag_changes_the_inventory(self) -> None:
        self.assertNotEqual(self.marks["wt3_teabag_taken"],
                            self.marks["wt3_teabag_selected"],
                            "the teabag was never picked up")

    def test_opening_the_icebox_changes_the_room(self) -> None:
        """A persistent world change: the door is drawn open."""
        self.assertNotEqual(self.marks["wt3_icebox_open"],
                            self.marks["wt3_teabag_taken"],
                            "the icebox did not open")

    def test_taking_from_a_room_container(self) -> None:
        """The mustard hotspot only exists because the icebox was opened."""
        self.assertNotEqual(self.marks["wt3_mustard_taken"],
                            self.marks["wt3_icebox_open"],
                            "the mustard was never taken")


class CourierTests(SegmentBase, unittest.TestCase):
    """Segment 4: the courier's package (2 points).

    This closes the loop opened by the phone call. Edsel promised to send
    the game "by courier as soon as I hang up", and the delivery arrives
    through the *same* scheduler that made the phone ring: the first WAIT
    after returning to the front hall reports "Time passes. You hear the
    doorbell sound.", and every later WAIT reports only "Time passes." --
    a one-shot scheduled event, not a poll.

    That cross-room, cross-segment causality is the point. The doorbell
    does not fire because we walked into the hall; it fires because a
    conversation several minutes earlier set a story flag that armed it.
    A port with a broken clock, a broken event queue or a broken story
    database reaches this room and waits forever.

    The parcel itself is left on the stoop rather than handed over, so it
    is only reachable once the front door is open -- another hotspot that
    does not exist until a world change publishes it.
    """

    SEGMENT = "walkthrough_04_courier"
    WITNESS = "wt4_package_taken.bmp"
    BUDGET = 9_000_000_000

    GOLDEN = {
        "wt4_hall_again":     "00172dcab397cd56",
        "wt4_doorbell":       "2de61ed0c5a9d041",
        "wt4_door_open":      "848e2d2d779bfafb",
        "wt4_package_taken":  "ad7131e71cff2549",
    }

    def test_the_doorbell_event_fired(self) -> None:
        self.assertNotEqual(self.marks["wt4_doorbell"],
                            self.marks["wt4_hall_again"],
                            "waiting in the hall produced nothing")

    def test_opening_the_door_changes_the_room(self) -> None:
        self.assertNotEqual(self.marks["wt4_door_open"],
                            self.marks["wt4_doorbell"],
                            "the front door did not open")

    def test_the_package_was_collected(self) -> None:
        self.assertNotEqual(self.marks["wt4_package_taken"],
                            self.marks["wt4_door_open"],
                            "the package is still on the stoop")


class CdRomTests(SegmentBase, unittest.TestCase):
    """Segment 5: booting the game-within-the-game (9 points).

    This finishes the Mundania opening at **31/31 points** and is where
    the story proper begins -- the final frame has Grundy Golem drawn on
    the monitor, waiting.

    Two nested containers in a row: the courier's parcel holds a game box
    ("You find a game box entitled 'Companions of Xanth'."), and the box
    holds five more objects ("You find a game manual, a CD-ROM, a
    warranty card, a red book, and a pair of 3D glasses."). One take
    becomes seven inventory items and the bar grows a scroll control.

    The insertion itself is a three-verb sequence on one hotspot -- Open
    the drive, Put the CD in it, Close it -- which is the first place the
    route uses **Put**, and so the first time an inventory item is used
    as the *indirect* object of a command rather than the direct one.
    """

    SEGMENT = "walkthrough_05_cdrom"
    WITNESS = "wt5_game_started.bmp"
    BUDGET = 16_000_000_000

    GOLDEN = {
        "wt5_bedroom":       "1e7afd4a718e261a",
        "wt5_game_box":      "472b8a223b36e523",
        "wt5_box_opened":    "246a6b34089b25df",
        "wt5_computer_on":   "7fa647328ff70e46",
        "wt5_tray_open":     "fa94dac93d0b72c0",
        "wt5_cd_selected":   "d36c2034dfdadd0b",
        "wt5_cd_inserted":   "b4d8a1c65527dd9f",
        "wt5_game_started":  "f8c162577b4c7362",
    }

    def test_nested_containers_unpack(self) -> None:
        """Parcel -> game box -> five objects. Each step must change the
        screen, because each adds icons to the inventory bar."""
        self.assertNotEqual(self.marks["wt5_game_box"],
                            self.marks["wt5_bedroom"],
                            "the parcel did not open")
        self.assertNotEqual(self.marks["wt5_box_opened"],
                            self.marks["wt5_game_box"],
                            "the game box did not open")

    def test_the_computer_turns_on(self) -> None:
        """A context verb ("Turn on") driving a persistent world change:
        "You flip the power switch and the computer screen lights up." """
        self.assertNotEqual(self.marks["wt5_computer_on"],
                            self.marks["wt5_box_opened"],
                            "the computer did not power up")

    def test_the_drive_opens(self) -> None:
        self.assertNotEqual(self.marks["wt5_tray_open"],
                            self.marks["wt5_computer_on"],
                            "the CD-ROM drive did not open")

    def test_put_uses_an_inventory_item_on_a_room_object(self) -> None:
        """The first indirect-object command in the route."""
        self.assertNotEqual(self.marks["wt5_cd_selected"],
                            self.marks["wt5_tray_open"],
                            "the CD-ROM inventory slot did not respond")
        self.assertNotEqual(self.marks["wt5_cd_inserted"],
                            self.marks["wt5_cd_selected"],
                            "the CD was never put in the drive")

    def test_the_opening_completes(self) -> None:
        """"[9 points] You close the CD-ROM drive." -- and Grundy Golem
        appears on the monitor, which is a different scene entirely."""
        self.assertNotEqual(self.marks["wt5_game_started"],
                            self.marks["wt5_cd_inserted"],
                            "closing the drive did not start the game")


class IntoXanthTests(SegmentBase, unittest.TestCase):
    """Segment 6: into Xanth, with Nada Naga as Companion.

    The opening ends with the game-within-the-game booted but not yet
    entered. Looking at the monitor zooms into it -- a full-screen view of
    a figure the narration will not name yet ("A strange male figure
    studies you expectantly", hotspot "tiny man") -- and talking to him
    introduces Grundy Golem:

        "Hi, I'm Grundy Golem. Welcome to the Game. It's my job to answer
        any questions you may have about Xanth, the Game, or your
        potential Companions."

    with a six-option menu. Taking the last option ("Okay, Grund. I'm
    ready to make my selection.") gets his warning -- "Pick wisely, young
    man. Xanth's a dangerous place and the Companion you pick could mean
    the difference between success and failure." -- and then the
    **companion gallery**, four selectable portraits.

    Choosing Nada enters Xanth: "You're in a dimly lit cavern. Nada
    stands beside you, getting her bearings."

    The narration is per-companion and correctly gendered -- Che gets
    "getting *his* bearings", Jenny and Nada "*her*" -- so the choice is
    genuinely threaded into the story state rather than cosmetic. This is
    the first segment outside Mundania, and the first with a companion
    NPC following the player.

    This segment is **save-anchored**: see build_anchor().
    """

    SEGMENT = "walkthrough_06_xanth"
    WITNESS = "wt6_in_xanth.bmp"
    BUDGET = 8_000_000_000
    ANCHORED = True

    GOLDEN = {
        "wt6_resumed":      "e6305abca7e6a705",
        "wt6_closeup":      "193ee23c12ac1d59",
        "wt6_grundy":       "48a73cb19f7724dc",
        "wt6_pick_wisely":  "5fc7be060c6533c7",
        "wt6_gallery":      "ad950860398ec709",
        "wt6_in_xanth":     "891b997e6874704f",
    }

    def test_the_anchor_save_restored(self) -> None:
        """If the restore silently failed we would be sitting at the
        title screen, and every later click would land on nothing."""
        self.assertNotIn(self.marks["wt6_resumed"], {"", None})
        self.assertNotEqual(self.marks["wt6_resumed"],
                            self.marks["wt6_closeup"],
                            "the screen never changed after restoring")

    def test_zooming_into_the_game(self) -> None:
        self.assertNotEqual(self.marks["wt6_closeup"],
                            self.marks["wt6_resumed"],
                            "looking at the monitor did nothing")

    def test_grundys_dialogue_opens_and_advances(self) -> None:
        self.assertNotEqual(self.marks["wt6_grundy"],
                            self.marks["wt6_closeup"],
                            "Grundy never spoke")
        self.assertNotEqual(self.marks["wt6_pick_wisely"],
                            self.marks["wt6_grundy"],
                            "asking to choose did not advance the dialogue")

    def test_the_companion_gallery_appears(self) -> None:
        self.assertNotEqual(self.marks["wt6_gallery"],
                            self.marks["wt6_pick_wisely"],
                            "the companion gallery never came up")

    def test_choosing_nada_enters_xanth(self) -> None:
        """A new region entirely -- a dimly lit cavern, with Nada in the
        party. Leaving Mundania is the end of the opening chapter."""
        self.assertNotEqual(self.marks["wt6_in_xanth"],
                            self.marks["wt6_gallery"],
                            "picking a companion did not start the game")


def run_cavern_segment(budget: int) -> tuple[str, int, dict]:
    """Play segment 7 from the in-cavern save, not the post-opening anchor.

    resume_in_xanth.xit restores whatever *.SAV is sitting in the save
    directory. build_anchor() / ANCHORED=True is the end of Mundania, so
    pointing segment 7 at it resumes the wrong room. The save that belongs
    here is the one anchor_in_xanth.xit writes (dimly lit cavern, Nada).
    A prebuilt copy lives at build/anchor_xanth; if it is absent, play
    segment 6 from the post-opening anchor and save over slot 1.
    """
    dest = SAVES / "walkthrough_07_cavern"
    if dest.exists():
        shutil.rmtree(dest)
    prebuilt = PROJECT_ROOT / "build" / "anchor_xanth"
    if (prebuilt / "XANTH000.SAV").is_file():
        shutil.copytree(prebuilt, dest)
    else:
        post = PROJECT_ROOT / "build" / "anchor_saves"
        if not (post / "XANTH000.SAV").is_file():
            post = build_anchor()
        shutil.copytree(post, dest)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(dest), "--insns", "12000000000",
             "--script", str(TRACES / "anchor_in_xanth.xit")],
            capture_output=True, text=True, timeout=1800, env=RUN_ENV,
        )
        out = proc.stdout + proc.stderr
        if "fault                 : ok" not in out or not list(dest.glob("*.SAV")):
            raise AssertionError(f"cavern anchor run failed:\n{out[-2000:]}")

    proc = subprocess.run(
        [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
         "--saves", str(dest),
         "--script", str(TRACES / "walkthrough_07_cavern.xit"),
         "--insns", str(budget)],
        capture_output=True, text=True, timeout=1800, env=RUN_ENV,
    )
    out = proc.stdout + proc.stderr
    marks = {m.group(1): m.group(2) for m in
             re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)", out)}
    return out, proc.returncode, marks


class CavernTests(SegmentBase, unittest.TestCase):
    """Segment 7: out of the dimly lit cavern (9 points, 40 total).

    Wearing the 3D glasses restores Mode 13h colour. Three WAITs, and not
    a fourth: Nada searches the walls, shifts to the second door, and it
    slides open with North lit. Going north and answering "No. This can't
    be real." gets her explanation that Dug is shaped like a screen, then
    "[9 points] Nada has successfully extricated you from the cavern.
    You're finally in Xanth."

    This segment does **not** use ANCHORED. That flag copies the
    post-opening save, and resume_in_xanth.xit would restore Mundania.
    See run_cavern_segment().
    """

    SEGMENT = "walkthrough_07_cavern"
    WITNESS = "wt7_cavern_escaped.bmp"
    #: Measured completion is 2.432e9 instructions. Headroom so a short
    #: budget cannot truncate the trace without saying so.
    BUDGET = 4_000_000_000
    ANCHORED = False

    GOLDEN = {
        "wt7_resumed":         "f15e07534d2f5df9",
        "wt7_glasses_worn":    "33da15a7bb6dd78e",
        "wt7_door_opened":     "b6ed7f6eca4606a2",
        "wt7_nada_speaks":     "d6069f2576582bc6",
        "wt7_option1_chosen":  "6acf0da8b6c2e5ee",
        "wt7_cavern_escaped":  "5d6e8db6615d8d05",
    }

    @classmethod
    def setUpClass(cls) -> None:
        # Not SegmentBase.setUpClass: that would honour ANCHORED and copy
        # the post-opening save, or wipe the directory and boot with none.
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACES / f"{cls.SEGMENT}.xit", "walkthrough trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")
        cls.out, cls.rc, cls.marks = run_cavern_segment(cls.BUDGET)

    def test_the_cavern_save_restored(self) -> None:
        """A failed restore sits on the title screen, and the glasses
        click would not change the picture into the colour cavern."""
        self.assertNotEqual(self.marks["wt7_resumed"],
                            self.marks["wt7_glasses_worn"],
                            "the screen never changed after restoring")

    def test_wearing_the_glasses_changes_the_cavern(self) -> None:
        self.assertNotEqual(self.marks["wt7_glasses_worn"],
                            self.marks["wt7_resumed"],
                            "the 3D glasses did nothing")

    def test_nada_opens_the_secret_door(self) -> None:
        """Three waits publish the open doorway. The picture has to
        change -- a still-closed door is the puzzle not being solved."""
        self.assertNotEqual(self.marks["wt7_door_opened"],
                            self.marks["wt7_glasses_worn"],
                            "waiting never opened the door")

    def test_nada_asks_and_the_reply_is_taken(self) -> None:
        """North, then the disbelief question, then "No. This can't be
        real." Each of those is a different screen."""
        self.assertNotEqual(self.marks["wt7_nada_speaks"],
                            self.marks["wt7_door_opened"],
                            "leaving the cavern did not reach Nada's question")
        self.assertNotEqual(self.marks["wt7_option1_chosen"],
                            self.marks["wt7_nada_speaks"],
                            "the dialogue option did not register")

    def test_extricated_onto_the_clearing(self) -> None:
        """[9 points] and the clearing outside the cavern mouth. Not the
        same picture as the dialogue that awards it."""
        self.assertNotEqual(self.marks["wt7_cavern_escaped"],
                            self.marks["wt7_option1_chosen"],
                            "Dug is still inside the dialogue")
        rooms = {self.marks["wt7_resumed"],
                 self.marks["wt7_glasses_worn"],
                 self.marks["wt7_door_opened"],
                 self.marks["wt7_nada_speaks"],
                 self.marks["wt7_option1_chosen"],
                 self.marks["wt7_cavern_escaped"]}
        self.assertEqual(len(rooms), 6, "two checkpoints hashed the same picture")


if __name__ == "__main__":
    unittest.main()
