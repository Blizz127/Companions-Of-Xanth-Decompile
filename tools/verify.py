#!/usr/bin/env python3
"""Verify pinned ISO / EXE / OVL hashes. Matching comes later; this only pins identity."""

from __future__ import annotations

import json
import sys
from pathlib import Path

from identify import identify_mz, identify_ovl
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
        reports = [
            _check("iso", target["iso"], required=False),
            _check("executable", target["executable"], required=True),
            _check("overlay", target["overlay"], required=True),
        ]
        exe = identify_mz((ROOT / target["executable"]["path"]).read_bytes())
        ovl = identify_ovl((ROOT / target["overlay"]["path"]).read_bytes())
        out = {
            "identity_status": target["identity_status"],
            "files": reports,
            "executable_kind": exe["kind"],
            "overlay_kind": ovl["kind"],
            "overlay_is_mz": ovl["is_mz"],
            "compiler": "UNKNOWN",
        }
        print(json.dumps(out, indent=2, sort_keys=True))
        return 0
    except RetailError as exc:
        print(f"verify: ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
