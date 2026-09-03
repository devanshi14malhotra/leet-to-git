class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        int oddCount = 0, evenCount = 0;

        for (int x : nums1) {
            if (x % 2 == 0) {
                evenCount++;
                minEven = min(minEven, x);
            } else {
                oddCount++;
                minOdd = min(minOdd, x);
            }
        }
        if (oddCount == 0) return true;
        if (evenCount == 0) return true;
        if (minOdd < minEven) return true;

        return false;
    }
};