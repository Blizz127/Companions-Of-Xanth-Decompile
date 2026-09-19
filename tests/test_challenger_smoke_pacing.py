#!/usr/bin/env python3
"""
Challenger M3 Automated Stress & Pacing Verification Script
Tests:
1. Smoke runner exact frame bounds (0, 1, 49, 50, 51) and phase transitions.
2. Headless CPU utilization during frame pacing (< 5%).
"""

import subprocess
import time
import sys
import re
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PORT_BIN = os.path.join(ROOT, "build", "xanth_port")

def test_frame_bounds():
    print("=== Testing Smoke Runner Exact Frame Bounds & Phase Transitions ===")
    test_cases = [
        {"frames": 0, "expected_ratio": 0.0, "should_pass": True},
        {"frames": 1, "expected_ratio": 0.0, "should_pass": True},
        {"frames": 49, "expected_ratio": 0.0, "should_pass": True},
        {"frames": 50, "expected_ratio": 100.0, "should_pass": True},
        {"frames": 51, "expected_ratio": 100.0, "should_pass": True},
    ]

    for tc in test_cases:
        frames = tc["frames"]
        cmd = [PORT_BIN, "--headless", "--frames", str(frames), "--test-boot"]
        proc = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)

        print(f"--- Running: {' '.join(cmd)} ---")
        print(f"Return code: {proc.returncode}")
        print(f"Output:\n{proc.stdout.strip()}")
        if proc.stderr:
            print(f"Stderr:\n{proc.stderr.strip()}")

        assert proc.returncode == 0, f"Expected returncode 0 for --frames {frames}, got {proc.returncode}"

        # Verify frame count line
        match_frame = re.search(r"\[SMOKE\] Frame (\d+) reached, non-black pixel ratio = ([\d\.]+)%", proc.stdout)
        assert match_frame is not None, f"Could not find frame status output for --frames {frames}"

        reported_frame = int(match_frame.group(1))
        reported_ratio = float(match_frame.group(2))

        assert reported_frame == frames, f"Expected frame {frames}, reported {reported_frame}"
        assert abs(reported_ratio - tc["expected_ratio"]) < 0.1, \
            f"For frame {frames}, expected ratio {tc['expected_ratio']}%, got {reported_ratio}%"

        # Verify BOOT_SUCCESS line
        assert "[SMOKE] BOOT_SUCCESS" in proc.stdout, f"Missing BOOT_SUCCESS for --frames {frames}"

        print(f"[VERIFIED] --frames {frames}: exact frame count = {reported_frame}, pixel ratio = {reported_ratio}%\n")

def test_cpu_utilization():
    print("=== Testing Headless Frame Pacing CPU Utilization ===")
    frames = 300
    cmd = [PORT_BIN, "--headless", "--frames", str(frames), "--test-boot"]

    # Measure wall time and process CPU times
    t0_wall = time.time()
    proc = subprocess.Popen(cmd, cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Use /proc/<pid>/stat if on Linux, or wait and measure using /usr/bin/time
    stdout, stderr = proc.communicate()
    t1_wall = time.time()
    elapsed_wall = t1_wall - t0_wall

    assert proc.returncode == 0, f" xanth_port failed with return code {proc.returncode}"

    # Now run via /usr/bin/time -v for precise kernel CPU metrics
    time_cmd = ["/usr/bin/time", "-v", PORT_BIN, "--headless", "--frames", str(frames), "--test-boot"]
    proc_time = subprocess.run(time_cmd, cwd=ROOT, capture_output=True, text=True)

    stderr_time = proc_time.stderr
    user_time_match = re.search(r"User time \(seconds\):\s+([\d\.]+)", stderr_time)
    sys_time_match = re.search(r"System time \(seconds\):\s+([\d\.]+)", stderr_time)
    percent_match = re.search(r"Percent of CPU this job got:\s+(\d+)%", stderr_time)

    assert user_time_match, "User time not found"
    assert sys_time_match, "System time not found"

    user_cpu = float(user_time_match.group(1))
    sys_cpu = float(sys_time_match.group(1))
    total_cpu = user_cpu + sys_cpu
    reported_percent = int(percent_match.group(1)) if percent_match else None

    # Calculate exact CPU percentage over wall time
    measured_percent = (total_cpu / elapsed_wall) * 100.0

    print(f"Frames: {frames}")
    print(f"Elapsed Wall Time: {elapsed_wall:.3f}s")
    print(f"User CPU Time: {user_cpu:.3f}s")
    print(f"System CPU Time: {sys_cpu:.3f}s")
    print(f"Total CPU Time: {total_cpu:.3f}s")
    print(f"Measured CPU Utilization: {measured_percent:.2f}%")
    if reported_percent is not None:
        print(f"Kernel Reported CPU Utilization: {reported_percent}%")

    assert measured_percent < 5.0, f"CPU utilization {measured_percent:.2f}% exceeded 5.0% threshold!"
    print("[VERIFIED] Headless frame pacing strictly yields CPU: utilization < 5.0%\n")

if __name__ == "__main__":
    test_frame_bounds()
    test_cpu_utilization()
    print("[ALL CHALLENGER SMOKE & PACING TESTS PASSED]")
