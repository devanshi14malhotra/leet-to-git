class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10];
        for (int i = 0; i <= 9; i++) freq[i] = 0;

        for (int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }

        int count = 0;

        for (int h = 1; h <= 9; h++) {
            if (freq[h] == 0) continue;
            for (int t = 0; t <= 9; t++) {
                if (freq[t] == 0) continue;
                for (int u = 0; u <= 9; u += 2) {
                    if (freq[u] == 0) continue;

                    int need[10];
                    for (int i = 0; i <= 9; i++) need[i] = 0;

                    need[h] = need[h] + 1;
                    need[t] = need[t] + 1;
                    need[u] = need[u] + 1;

                    bool ok = true;
                    for (int digit = 0; digit <= 9; digit++) {
                        if (need[digit] > freq[digit]) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};