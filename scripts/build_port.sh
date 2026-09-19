#!/usr/bin/env bash
# scripts/build_port.sh — Automated Native Port Build Script (Linux GCC/Clang)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

echo "===================================================================="
echo " Building Companions of Xanth Native Port (Linux GCC/Clang)"
echo " Workspace : ${ROOT_DIR}"
echo " Build Dir : ${BUILD_DIR}"
echo "===================================================================="

# Ensure CMake is available
if ! command -v cmake >/dev/null 2>&1; then
    echo "[ERROR] cmake binary not found in PATH." >&2
    exit 1
fi

# Detect parallel CPU count
NPROC=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 2)

mkdir -p "${BUILD_DIR}"

echo "[1/2] Configuring CMake build..."
cmake -S "${ROOT_DIR}/port" \
      -B "${BUILD_DIR}" \
      -DCMAKE_BUILD_TYPE=Release

echo "[2/2] Compiling xanth_port executable (parallelism: ${NPROC})..."
cmake --build "${BUILD_DIR}" --config Release -j"${NPROC}"

if [[ -f "${BUILD_DIR}/xanth_port" ]]; then
    echo "===================================================================="
    echo " BUILD SUCCESS: ${BUILD_DIR}/xanth_port"
    echo "===================================================================="
    exit 0
else
    echo "[ERROR] Build target xanth_port was not created." >&2
    exit 1
fi
