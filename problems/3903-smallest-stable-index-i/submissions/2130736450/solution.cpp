class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=0; i<n; i++){
            int lmax = nums[0];
            int rmin = nums[i];
            for (int j=0; j<=i; j++){
                lmax = max(lmax,nums[j]);
            }
            for (int j=i; j<n; j++){
                rmin = min(rmin, nums[j]);
            }
            if (lmax - rmin <= k){
                return i;
            }
        }
        return -1;
    }
};