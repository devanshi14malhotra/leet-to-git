class Solution {
public:
    int slidingWindowTemplate(string s) {
        int left = 0, ans = 0;
        int n = s.length();
        // any tracking structure: array, map, set, running sum, etc.
        unordered_map<char, int> freq;

        for (int right = 0; right < n; ++right) {
            // 1. add s[right] into the window
            freq[s[right]]++;

            // 2. shrink from left while window breaks the rule
            while (/* window invalid */) {
                freq[s[left]]--;
                left++;
            }

            // 3. window [left, right] is valid now — update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
