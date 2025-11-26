"""Direct runner for multiplayer integration test (avoids full pytest).

Usage:
    python tools/run_integration.py
"""
import os
import sys
import time

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if PROJECT_ROOT not in sys.path:
    sys.path.insert(0, PROJECT_ROOT)

from tests.test_multiplayer_integration import test_udp_lobby_forwards_pos  # noqa: E402

if __name__ == "__main__":
    print("Running integration test (direct runner): test_udp_lobby_forwards_pos")
    try:
        test_udp_lobby_forwards_pos()
        print("INTEGRATION TEST PASSED")
    except AssertionError as e:
        print("INTEGRATION TEST FAILED (assertion):", e)
    except (OSError, RuntimeError, ValueError) as e:
        print("INTEGRATION TEST ERROR (runtime):", e)
    finally:
        # allow background threads to clean up
        time.sleep(0.1)
