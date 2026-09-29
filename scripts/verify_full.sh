#!/usr/bin/env bash
# Full verification, including everything that needs the retail disc.
#
# Public CI cannot run this: the disc must not be committed or uploaded. A
# green public CI badge means "builds, and the CPU is correct on five
# toolchains". THIS script is what means "the game actually runs".
set -euo pipefail
cd "$(dirname "$0")/.."

echo "=== repository contains no indexed retail game data ==="
python3 scripts/check_no_game_data.py

echo "=== build (must be warning-free) ==="
cmake -B build -S port >/dev/null
cmake --build build --clean-first -j"$(nproc)" >build/build.log 2>&1 || {
    tail -30 build/build.log; echo "FAIL: build error"; exit 1; }
if grep -qE "warning:|error:" build/build.log; then
    grep -E "warning:|error:" build/build.log | head -20
    echo "FAIL: build produced warnings"; exit 1
fi
echo "ok, no warnings"

echo
echo "=== CPU conformance (no SDL, no assets) ==="
./build/xanth_cpu_tests | tail -1

echo
echo "=== port test suite (ctest) ==="
SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy \
    ctest --test-dir build --output-on-failure | tail -4

echo
echo "=== MZ loader vs the Python reference ==="
python3 -m unittest discover -s tests -p "test_mzload.py" 2>&1 | tail -1

echo
echo "=== decompilation: ratchets and byte-for-byte rebuild ==="
python3 tools/coverage.py | tail -3
python3 -m unittest discover -s tests -p "test_units.py" 2>&1 | tail -1
python3 tools/verify.py

echo
echo "ALL GREEN"
