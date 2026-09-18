class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == n) first[c] = i;
            last[c] = i;
        }

        vector<string> result;
        int prevEnd = -1;

        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;

            int end = last[s[i] - 'a'];
            bool valid = true;

            for (int k = i; k <= end; k++) {
                int c = s[k] - 'a';
                if (first[c] < i) {
                    valid = false;
                    break;
                }
                end = max(end, last[c]);
            }

            if (!valid) continue;

            if (i > prevEnd) result.push_back("");
            prevEnd = end;
            result.back() = s.substr(i, end - i + 1);
        }
        return result;
    }
};