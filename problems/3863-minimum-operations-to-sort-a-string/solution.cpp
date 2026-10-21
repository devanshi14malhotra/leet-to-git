class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) return 1;

        // max is unique at the front AND min is unique at the back
        bool maxOnlyFront = (s[0] == mx) && count(s.begin(), s.end(), mx) == 1;
        bool minOnlyBack  = (s[n - 1] == mn) && count(s.begin(), s.end(), mn) == 1;

        if (maxOnlyFront && minOnlyBack) return 3;

        return 2;
    }
};