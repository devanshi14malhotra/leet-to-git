class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int count=0;
        for (int num:nums){
            if (num==0) {
                res=max(res,count);
                count=0;
            } else {
                count++;
            }
        }
        return max(res,count);
    }
};