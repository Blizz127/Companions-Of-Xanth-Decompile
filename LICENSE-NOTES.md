# License and provenance notes

The game, its executable, overlay, and all disc content are copyrighted by
their respective rightsholders. This repository contains tooling,
documentation, and developer-authored scaffolding only; it does not grant
permission to redistribute retail data.

Contributors must provide their own legally obtained copy of the 1997
budget CD (volume `XANBUD`). Retail payloads are ignored by `.gitignore`
and must remain outside version control. Only deterministic metadata such
as media size, SHA-256, ISO member paths, and executable identity may be
recorded.

The eventual modern port must be built from the decompilation and must
preserve the provenance boundary: retail bytes are an oracle for matching
and validation, not a payload to copy into a distributed port.
