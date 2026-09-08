#!/usr/bin/env python3
"""Pin identity, then rebuild and byte-compare EXE and OVL. Fail closed."""

from __future__ import annotations

import json
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from identify import identify_mz, identify_ovl
from rebuild import rebuild_and_compare
from retail_common import ROOT, RetailError, load_target, verify_file


def _check(label: str, pin: dict, *, required: bool) -> dict:
    path = ROOT / pin["path"]
    if not path.is_file():
        if required:
            raise RetailError(f"missing {label}: {path}")
        return {"label": label, "status": "ABSENT", "path": str(path)}
    digest = verify_file(path, expected_size=pin["size"], expected_sha256=pin["sha256"])
    return {"label": label, "status": "VERIFIED", "path": str(path), "sha256": digest, "size": pin["size"]}


def main() -> int:
    try:
        target = load_target(ROOT)
        files = [
            _check("iso", target["iso"], required=False),
            _check("executable", target["executable"], required=True),
            _check("overlay", target["overlay"], required=True),
        ]
        exe = identify_mz((ROOT / target["executable"]["path"]).read_bytes())
        ovl = identify_ovl((ROOT / target["overlay"]["path"]).read_bytes())
        match = rebuild_and_compare(ROOT)
        unmatched = []
        if match["executable"]["result"] != "BINARY-MATCH":
            unmatched.append("XANTH.EXE")
        if match["overlay"]["result"] != "BINARY-MATCH":
            unmatched.append("XANTH.OVL")
        out = {
            "identity_status": target["identity_status"],
            "files": files,
            "executable_kind": exe["kind"],
            "overlay_kind": ovl["kind"],
            "overlay_is_mz": ovl["is_mz"],
            "compiler": match["compiler"],
            "match": match,
            "unmatched": unmatched,
            "result": match["result"],
        }
        print(json.dumps(out, indent=2, sort_keys=True))
        return 0 if match["result"] == "BINARY-MATCH" and not unmatched else 1
    except RetailError as exc:
        print(f"verify: ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
