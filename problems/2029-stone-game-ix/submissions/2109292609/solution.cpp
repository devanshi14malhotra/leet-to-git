class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};
        for (int i = 0; i < stones.size(); i++) {
            int remainder = stones[i] % 3;
            count[remainder]++;
        }
        if (count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }
        int diff = count[1] - count[2];
        if (diff < 0) {
            diff = -diff;
        }
        return diff > 2;
    }
};