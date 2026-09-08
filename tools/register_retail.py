#!/usr/bin/env python3
"""Register and verify the pinned Companions of Xanth budget CD."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from retail_common import ROOT, RetailError, load_json, load_target, verify_file, write_json_atomic


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("iso", nargs="?", type=Path, default=None)
    parser.add_argument("--manifest", type=Path, help="manifest JSON (default: provenance/manifest.json)")
    parser.add_argument("--dry-run", action="store_true", help="verify only; do not update provenance")
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    target = load_target(ROOT)
    iso_pin = target["iso"]
    iso_path = (args.iso or ROOT / iso_pin["path"]).expanduser().resolve()
    manifest_path = (args.manifest or ROOT / "provenance/manifest.json").resolve()
    try:
        digest = verify_file(
            iso_path,
            expected_size=iso_pin["size"],
            expected_sha256=iso_pin["sha256"],
        )
        manifest = {}
        if manifest_path.is_file():
            manifest = load_json(manifest_path)
        media = manifest.setdefault("media", {})
        if not isinstance(media, dict):
            raise RetailError("provenance/manifest.json media field must be an object")
        try:
            recorded_path = str(iso_path.relative_to(ROOT))
        except ValueError:
            recorded_path = str(iso_path)
        media["source_path"] = recorded_path
        media["size_bytes"] = iso_pin["size"]
        media["sha256"] = digest
        media["volume"] = iso_pin["volume"]
        if not args.dry_run:
            write_json_atomic(manifest_path, manifest)
        print(f"ISO VERIFIED size={iso_pin['size']} sha256={digest}")
        print(f"manifest={'DRY_RUN' if args.dry_run else 'UPDATED'} path={manifest_path}")
        return 0
    except RetailError as exc:
        print(f"register_retail: ERROR: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
