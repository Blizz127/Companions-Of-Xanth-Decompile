"""Extract 16-bit LEDATA payloads from an MSC OMF object."""

from __future__ import annotations


class OmfError(ValueError):
    pass


def ledata_code(data: bytes) -> bytes:
    i = 0
    chunks: list[tuple[int, bytes]] = []
    while i + 3 <= len(data):
        typ = data[i]
        length = int.from_bytes(data[i + 1 : i + 3], "little")
        rec = data[i + 3 : i + 3 + length]
        i += 3 + length
        if i > len(data) or not rec:
            raise OmfError("truncated OMF record")
        payload = rec[:-1]
        if typ == 0xA0:
            if len(payload) < 3:
                raise OmfError("short LEDATA")
            offset = int.from_bytes(payload[1:3], "little")
            chunks.append((offset, payload[3:]))
    if not chunks:
        raise OmfError("no LEDATA16 records")
    size = max(off + len(blob) for off, blob in chunks)
    out = bytearray(size)
    for off, blob in chunks:
        out[off : off + len(blob)] = blob
    return bytes(out)
