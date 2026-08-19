class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mask;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];
            if (col >= 2 && col <= 9) {
                mask[row] = mask[row] | (1 << (col - 2));
            }
        }
        long long ans = (long long)(n - mask.size()) * 2;

        unordered_map<int, int>::iterator it;
        for (it = mask.begin(); it != mask.end(); it++) {
            int m = it->second;
            bool leftFree  = (m & 15) == 0;
            bool midFree   = (m & 60) == 0;
            bool rightFree = (m & 240) == 0;

            if (leftFree && rightFree) ans += 2;
            else if (leftFree || midFree || rightFree) ans += 1;
        }
        return ans;
    }
};