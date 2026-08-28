class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        string ans;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';

            for (int c = t + 1; c < 26; c++)
                if (cnt[c]) {
                    string res = target.substr(0, i) + char('a' + c);
                    cnt[c]--;
                    for (int x = 0; x < 26; x++)
                        res += string(cnt[x], 'a' + x);
                    cnt[c]++;
                    ans = res;
                    break;
                }

            if (!cnt[t]) break;
            cnt[t]--;
        }

        return ans;
    }
};