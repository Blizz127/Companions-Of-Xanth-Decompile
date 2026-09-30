#!/usr/bin/env python3
"""The guest-state observer must not report field-idle behind a modal page.

Boots the real game under tool_vmboot with --guest-state, presses the
retail L key (Look), which opens a full-page description that waits for a
key without polling get_event from another site, and samples the observer
after every slice. Field-idle is required before L, forbidden while the page
is up, and required again after Space dismisses it.

Requires the retail data in game_cd/XANTH; nothing is written to git.
"""
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
VMBOOT = os.environ.get("XANTH_VMBOOT", os.path.join(ROOT, "build", "tool_vmboot"))
DATA = os.environ.get("XANTH_DATA", os.path.join(ROOT, "game_cd", "XANTH"))
TRACES = os.path.join(ROOT, "tests", "traces")


def main():
    if not os.path.exists(os.path.join(DATA, "XANTH.EXE")):
        if "XANTH_DATA" in os.environ:
            print("FAIL: explicitly selected owned data is missing")
            return 1
        print("SKIP: retail data not present")
        return 77
    with tempfile.TemporaryDirectory(prefix="xanth-gs-") as work:
        script = os.path.join(work, "modal.xit")
        lines = [f"include {os.path.join(TRACES, 'lib', 'boot.xit')}", "run 10",
                 "key 108 38"]
        lines += ["run 2"] * 12
        lines += ["key 32"] + ["run 2"] * 6
        with open(script, "w") as f:
            f.write("\n".join(lines) + "\n")
        env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")
        for name in ("DISPLAY", "WAYLAND_DISPLAY", "XAUTHORITY"):
            env.pop(name, None)
        proc = subprocess.run(
            [VMBOOT, "--exe", os.path.join(DATA, "XANTH.EXE"), "--data", DATA,
             "--saves", work, "--script", script, "--insns", "3000000000", "--guest-state"],
            env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=900)
        log = proc.stderr
        # Map each executed script step to the classification logged after it.
        states = [m.group(1) for m in re.finditer(r"\[guest-state\] step \d+ (\S+)", log)]
        if proc.returncode not in (0,) or not states:
            print(log[-2000:])
            print("FAIL: tool_vmboot did not run the script")
            return 1
        try:
            k_l = next(i for i, l in enumerate(re.finditer(r"\[script\] (.*)", log))
                       if l.group(1).startswith("key 108"))
            k_space = next(i for i, l in enumerate(re.finditer(r"\[script\] (.*)", log))
                           if l.group(1).startswith("key 32") and i > k_l)
        except StopIteration:
            print("FAIL: key steps not found")
            return 1
        before = states[k_l - 1]
        during = states[k_l + 1:k_space]
        after = states[-1]
        print(f"before L: {before}; while the page is up: {sorted(set(during))}; after Space: {after}")
        if before != "field-idle":
            print("FAIL: not field-idle before L")
            return 1
        if len(during) < 10 or "field-idle" in during:
            print("FAIL: reported field-idle behind the L page")
            return 1
        if after != "field-idle":
            print("FAIL: not field-idle after dismissing the page")
            return 1
        print("PASS")
        return 0


if __name__ == "__main__":
    sys.exit(main())
