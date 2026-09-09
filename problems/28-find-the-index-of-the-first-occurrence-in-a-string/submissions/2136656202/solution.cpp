class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        // build failure function (lps[i] = length of longest proper prefix of needle[0..i] that's also a suffix)
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m; i++) {
            while (len > 0 && needle[i] != needle[len]) len = lps[len - 1];
            if (needle[i] == needle[len]) len++;
            lps[i] = len;
        }

        // scan haystack using the failure function
        int j = 0; // matched length in needle
        for (int i = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) j = lps[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == m) return i - m + 1;
        }

        return -1;
    }
};