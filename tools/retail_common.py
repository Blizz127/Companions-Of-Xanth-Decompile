"""Fail-closed helpers for the XANBUD provenance pipeline."""

from __future__ import annotations

import hashlib
import json
import os
import tempfile
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parents[1]


class RetailError(RuntimeError):
    """A user-actionable provenance or extraction failure."""


def sha256_file(path: Path, chunk_size: int = 1024 * 1024) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        while chunk := stream.read(chunk_size):
            digest.update(chunk)
    return digest.hexdigest()


def verify_file(path: Path, *, expected_size: int, expected_sha256: str) -> str:
    if not path.exists():
        raise RetailError(f"retail file does not exist: {path}")
    if not path.is_file():
        raise RetailError(f"retail file is not a regular file: {path}")
    actual_size = path.stat().st_size
    if actual_size != expected_size:
        raise RetailError(
            f"size mismatch for {path}: expected {expected_size} bytes, got {actual_size}"
        )
    actual_sha256 = sha256_file(path)
    if actual_sha256.lower() != expected_sha256.lower():
        raise RetailError(
            f"SHA-256 mismatch for {path}: expected {expected_sha256}, got {actual_sha256}"
        )
    return actual_sha256


def load_json(path: Path) -> dict[str, Any]:
    try:
        with path.open("r", encoding="utf-8") as stream:
            value = json.load(stream)
    except (OSError, json.JSONDecodeError) as exc:
        raise RetailError(f"cannot read JSON {path}: {exc}") from exc
    if not isinstance(value, dict):
        raise RetailError(f"JSON root must be an object: {path}")
    return value


def write_json_atomic(path: Path, value: dict[str, Any], *, dry_run: bool = False) -> None:
    if dry_run:
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, temporary = tempfile.mkstemp(prefix=f".{path.name}.", suffix=".tmp", dir=path.parent)
    temporary_path = Path(temporary)
    try:
        with os.fdopen(fd, "w", encoding="utf-8") as stream:
            json.dump(value, stream, indent=2, sort_keys=True)
            stream.write("\n")
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary_path, path)
    except Exception:
        temporary_path.unlink(missing_ok=True)
        raise


def load_target(root: Path | None = None) -> dict[str, Any]:
    return load_json((root or ROOT) / "config/target.json")
