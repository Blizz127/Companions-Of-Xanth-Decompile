#!/usr/bin/env bash
# scripts/run_smoke_test.sh — Automated Headless Smoke Test Runner
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"
BIN="${BUILD_DIR}/xanth_port"
DATA_DIR="${ROOT_DIR}/game_cd/XANTH"

echo "===================================================================="
echo " Executing Automated Headless Smoke Test (300 Frames)"
echo " Root: ${ROOT_DIR}"
echo "===================================================================="

if [[ ! -x "${BIN}" ]]; then
    echo "Executable not found at ${BIN}. Triggering build..."
    "${SCRIPT_DIR}/build_port.sh"
fi

export SDL_VIDEODRIVER=dummy
export SDL_AUDIODRIVER=dummy

SHOT="${BUILD_DIR}/smoke_shot.bmp"
rm -f "${SHOT}"

if [[ ! -d "${DATA_DIR}" ]]; then
    echo "[FAIL] Runtime assets are missing. Supply the XANBUD files in ${DATA_DIR} or pass --data to xanth_port." >&2
    exit 2
fi

echo "Running: ${BIN} --headless --frames 300 --data \"${DATA_DIR}\" --shot \"${SHOT}\""

set +e
OUTPUT=$("${BIN}" --headless --frames 300 --data "${DATA_DIR}" --shot "${SHOT}" 2>&1)
EXIT_CODE=$?
set -e

echo "${OUTPUT}"

if [[ ${EXIT_CODE} -ne 0 ]]; then
    echo "[FAIL] Smoke test failed with exit code ${EXIT_CODE}" >&2
    exit ${EXIT_CODE}
fi

if [[ -s "${SHOT}" ]]; then
    echo "===================================================================="
    echo " SMOKE TEST PASSED: Title & intro ran cleanly for 300 frames."
    echo " Shot artifact: ${SHOT}"
    echo "===================================================================="
    exit 0
else
    echo "[FAIL] Shot artifact not written to ${SHOT}." >&2
    exit 1
fi
