class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortedNums=nums;
        sort(sortedNums.begin(), sortedNums.end());
        for (int i=0; i<n; i++){
            bool match=true;
            int idx=0;
            for (int j=n-i; j<n && match; j++){
                if (nums[idx] != sortedNums[j]){
                    match=false;
                }
                idx++;
            }
            for (int j=0; j<n-i && match; j++){
                if (nums[idx] != sortedNums[j]){
                    match=false;
                }
                idx++;
            }
            if (match) return true;
        }
        return false;
    }
};