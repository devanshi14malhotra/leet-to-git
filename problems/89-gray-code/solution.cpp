class Solution {
public:
    vector<int> grayCode(int n) {
        int totalCount = 1 << n;
        vector<int> result;
        for (int i = 0; i < totalCount; i++) {
            int grayValue = i ^ (i >> 1);
            result.push_back(grayValue);
        }
        return result;
    }
};