#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
if [[ -x "$SCRIPT_DIR/xanth_port" ]]; then
  HERE="$SCRIPT_DIR"
else
  HERE="$(cd -- "$SCRIPT_DIR/.." && pwd)"
fi
DEFAULT_DATA="${HOME:-}/Games/companions-of-xanth/data"
SAVES="${XANTH_SAVES:-${XDG_DATA_HOME:-${HOME:-.}/.local/share}/companions-of-xanth/saves}"
DATA_ARGS=()

# Leave --data unspecified for the normal one-click path. The VM can then use
# its remembered first-run choice; its built-in default is DEFAULT_DATA.
if (($# > 0)) && [[ "$1" != -* ]]; then
  DATA_ARGS=(--data "$1")
  shift
elif [[ -n "${XANTH_DATA:-}" ]]; then
  DATA_ARGS=(--data "$XANTH_DATA")
fi

mkdir -p "$SAVES"
export LD_LIBRARY_PATH="$HERE/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$HERE/xanth_port" "${DATA_ARGS[@]}" --saves "$SAVES" "$@"
