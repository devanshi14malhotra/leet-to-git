class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), count = 0, left = 0;
        string ans = "";
        for (int right = 0; right < n; right++) {
            count += s[right] - '0';
            while (count > k || (count == k && s[left] == '0'))
                count -= s[left++] - '0';
            if (count == k) {
                string candidate = s.substr(left, right - left + 1);
                if (ans.empty() || candidate.size() < ans.size() ||
                    (candidate.size() == ans.size() && candidate < ans))
                    ans = candidate;
            }
        }
        return ans;
    }
};