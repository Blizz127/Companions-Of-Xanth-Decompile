"""Pure byte compare. Two buffers in; BINARY-MATCH or DIFF out. No truncation."""

from __future__ import annotations


def compare_bytes(original: bytes, rebuilt: bytes) -> dict:
    if original == rebuilt:
        return {
            "result": "BINARY-MATCH",
            "original_size": len(original),
            "rebuilt_size": len(rebuilt),
            "first_diff": None,
        }
    limit = min(len(original), len(rebuilt))
    first = next((i for i in range(limit) if original[i] != rebuilt[i]), limit)
    return {
        "result": "DIFF",
        "original_size": len(original),
        "rebuilt_size": len(rebuilt),
        "first_diff": first,
        "original_at": original[first : first + 16].hex() if first < len(original) else "",
        "rebuilt_at": rebuilt[first : first + 16].hex() if first < len(rebuilt) else "",
    }
