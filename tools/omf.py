"""Extract 16-bit LEDATA payloads from an MSC OMF object."""

from __future__ import annotations


class OmfError(ValueError):
    pass


def _index(payload: bytes, cursor: int) -> tuple[int, int]:
    if cursor >= len(payload):
        raise OmfError("truncated OMF index")
    value = payload[cursor]
    if value & 0x80:
        if cursor + 1 >= len(payload):
            raise OmfError("truncated OMF long index")
        return ((value & 0x7F) << 8) | payload[cursor + 1], cursor + 2
    return value, cursor + 1


_LOC_SIZE = {0: 1, 1: 2, 2: 2, 3: 4, 4: 1, 5: 2, 9: 4, 13: 6}


def _fixups(payload: bytes, ledata_base: int) -> list[tuple[int, int]]:
    cursor = 0
    found: list[tuple[int, int]] = []
    while cursor < len(payload):
        lead = payload[cursor]
        if (lead & 0x80) == 0:
            cursor += 1
            method = (lead >> 2) & 7
            if method in (0, 1, 2, 3):
                _, cursor = _index(payload, cursor)
            continue
        if cursor + 2 > len(payload):
            break
        locat_hi = payload[cursor]
        locat_lo = payload[cursor + 1]
        data_offset = ((locat_hi & 3) << 8) | locat_lo
        loc_type = (locat_hi >> 2) & 0xF
        cursor += 2
        if cursor >= len(payload):
            break
        fixdat = payload[cursor]
        cursor += 1
        frame_from_thread = (fixdat >> 7) & 1
        frame_method = (fixdat >> 4) & 7
        target_from_thread = (fixdat >> 3) & 1
        has_displacement = ((fixdat >> 2) & 1) == 0
        if frame_from_thread == 0 and frame_method in (0, 1, 2, 3):
            _, cursor = _index(payload, cursor)
        if target_from_thread == 0:
            _, cursor = _index(payload, cursor)
        if has_displacement:
            cursor += 2
        found.append((ledata_base + data_offset, _LOC_SIZE.get(loc_type, 2)))
    return found


def ledata_and_fixups(data: bytes) -> tuple[bytes, list[tuple[int, int]]]:
    """LEDATA of the *code* segment, plus its fixups.

    A translation unit can emit more than one segment: a source containing
    string literals puts them in a data segment whose LEDATA offsets start
    at the same place as the code's. Merging every LEDATA by offset — which
    this used to do — let the literals overwrite the first bytes of the
    function, so the comparison saw data instead of code and differed at
    +0. CL emits the code segment first, so its segment index is taken from
    the first LEDATA record and later segments are ignored. For the
    single-segment objects that make up the rest of the corpus this is a
    no-op.
    """
    i = 0
    chunks: list[tuple[int, bytes]] = []
    fixups: list[tuple[int, int]] = []
    last_base = 0
    code_segment: int | None = None
    skipped = 0
    while i + 3 <= len(data):
        typ = data[i]
        length = int.from_bytes(data[i + 1 : i + 3], "little")
        rec = data[i + 3 : i + 3 + length]
        i += 3 + length
        if i > len(data) or not rec:
            raise OmfError("truncated OMF record")
        payload = rec[:-1]
        if typ == 0x90 and len(payload) >= 3:
            # PUBDEF names the segment its symbol lives in, which is the code
            # segment for the function we are recovering. Neither "the first
            # LEDATA" nor "the lowest segment index" is safe: for a TU with
            # static data, CL emits the data segment's LEDATA *first*.
            _, cursor = _index(payload, 0)  # group
            segment, _ = _index(payload, cursor)
            if code_segment is None:
                code_segment = segment
        elif typ == 0xA0:
            if len(payload) < 3:
                raise OmfError("short LEDATA")
            segment = payload[0]
            if code_segment is None:
                code_segment = segment
            if segment != code_segment:
                skipped += 1
                continue
            last_base = int.from_bytes(payload[1:3], "little")
            chunks.append((last_base, payload[3:]))
        elif typ == 0x9C and chunks:
            fixups.extend(_fixups(payload, last_base))
    if not chunks:
        raise OmfError("no LEDATA16 records")
    size = max(off + len(blob) for off, blob in chunks)
    out = bytearray(size)
    for off, blob in chunks:
        out[off : off + len(blob)] = blob
    return bytes(out), fixups


def ledata_code(data: bytes) -> bytes:
    code, _fix = ledata_and_fixups(data)
    return code
