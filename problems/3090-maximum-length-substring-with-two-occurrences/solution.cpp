class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0;
        int n = s.length();

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};