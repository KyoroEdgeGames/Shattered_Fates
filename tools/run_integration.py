"""Simple runner to execute the multiplayer integration test without pytest.

Usage:
    python tools/run_integration.py
"""
import sys
import time

sys.path.insert(0, r'c:\Users\liama\OneDrive\Documents\Shattered_Fates')
from tests.test_multiplayer_integration import test_udp_lobby_forwards_pos

if __name__ == "__main__":
    print("Running integration test (direct runner): test_udp_lobby_forwards_pos")
    try:
        test_udp_lobby_forwards_pos()
        print("INTEGRATION TEST PASSED")
    except AssertionError as e:
        print("INTEGRATION TEST FAILED (assertion):", e)
    except Exception as e:
        print("INTEGRATION TEST ERROR:", e)
    finally:
        # allow background threads to clean up
        time.sleep(0.1)
