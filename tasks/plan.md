# Implementation Plan: target-pin (complete) then compiler-id

## Overview

Stand up a byte-identical matching decomp of *Companions of Xanth* from the
XANBUD budget CD. First module pins the retail binaries. Second module
identifies the historical compiler. Matching and function recovery follow.
A modern port is last and is derived from matched source.

## Architecture Decisions

- Two matching units: `XANTH.EXE` and `XANTH.OVL`. Neither is optional.
- Retail bytes are authority. No game data in git.
- Compiler remains UNKNOWN until a controlled experiment says otherwise.
- `pc-port` must not start as a replacement engine.

## Task List

See `tasks/todo.md`.

## Risks and Mitigations

| Risk | Impact | Mitigation |
|---|---|---|
| 16-bit overlay matching needs the original overlay linker | High | Identify overlay scheme before reconstructing functions that live in `.OVL` |
| CRT 1992 string is not an exact compiler build | High | Treat Microsoft C 7 / VC++ 1.x as candidates only |
| Floppy SKU may differ | Med | This disc is the only authority; do not mix dumps |

## Open Questions

- Exact overlay linker (Microsoft `/OVERLAY` vs third-party)
- Whether EXE tail bytes are overlay payload, appended data, or both
