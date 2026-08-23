class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum1 = 0, count1 = 0, sum2 = 0, count2 = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') count1++;
            else sum1 += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') count2++;
            else sum2 += num[i] - '0';
        }
        int count = count1 + count2;
        if (count % 2 == 1) return true;
        int diff = sum1 - sum2;
        return diff != (count2 - count1) * 9 / 2;
    }
};