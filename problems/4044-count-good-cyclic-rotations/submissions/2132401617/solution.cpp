class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n/2;
        long long s = 0;
        for (int num : nums) s += num;
        long long wsum=0;
        for (int i=0; i<half; i++){
            wsum += nums[i];
        }
        int count = 0;
        for (int r=0; r<n; r++){
            if (2*wsum > s) count++;
                wsum -= nums[r];
                wsum += nums[(r+half) % n];
        }
        return count;
    }
};