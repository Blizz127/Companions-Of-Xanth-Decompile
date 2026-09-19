#!/usr/bin/env bash
# scripts/run_smoke_test.sh — Automated Headless Smoke Test Runner
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"
BIN="${BUILD_DIR}/xanth_port"

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

echo "Running: ${BIN} --headless --frames 300 --data \"${ROOT_DIR}/original\" --test-boot"

set +e
OUTPUT=$("${BIN}" --headless --frames 300 --data "${ROOT_DIR}/original" --test-boot 2>&1)
EXIT_CODE=$?
set -e

echo "${OUTPUT}"

if [[ ${EXIT_CODE} -ne 0 ]]; then
    echo "[FAIL] Smoke test failed with exit code ${EXIT_CODE}" >&2
    exit ${EXIT_CODE}
fi

if echo "${OUTPUT}" | grep -q "BOOT_SUCCESS"; then
    echo "===================================================================="
    echo " SMOKE TEST PASSED: Title & intro ran cleanly for 300 frames."
    echo "===================================================================="
    exit 0
else
    echo "[FAIL] BOOT_SUCCESS marker not observed in test output." >&2
    exit 1
fi
