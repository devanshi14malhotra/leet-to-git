import importlib.util
import os
import sys
import types
import unittest
from unittest.mock import patch

MODULE_PATH = os.path.join(os.path.dirname(__file__), "..", "scripts", "sync.py")
SPEC = importlib.util.spec_from_file_location("sync_module", MODULE_PATH)
mod = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(mod)


class SyncAuthTests(unittest.TestCase):
    def test_fetch_recent_accepted_submissions_raises_clear_auth_error_on_401(self):
        with patch.object(mod.requests, "get") as mock_get:
            mock_get.return_value.status_code = 401
            mock_get.return_value.raise_for_status.side_effect = AssertionError("should not be called")

            with self.assertRaises(mod.LeetCodeAuthError) as cm:
                mod.fetch_recent_accepted_submissions(limit=50)

        self.assertIn("expired or invalid", str(cm.exception))
        self.assertIn("LEETCODE_SESSION", str(cm.exception))

    def test_main_exits_with_nonzero_status_when_auth_is_invalid(self):
        with patch.object(mod, "require_config", return_value=None), \
             patch.object(mod, "load_sync_log", return_value=set()), \
             patch.object(mod, "fetch_recent_accepted_submissions", side_effect=mod.LeetCodeAuthError("expired")):
            with self.assertRaises(SystemExit) as cm:
                mod.main()

        self.assertEqual(cm.exception.code, 1)


if __name__ == "__main__":
    unittest.main()
