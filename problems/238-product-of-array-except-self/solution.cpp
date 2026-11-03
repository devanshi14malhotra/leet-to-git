class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeros = 0;
        for (int num : nums){
            if (num != 0){
                prod *= num;
            } else {
                zeros++;
            }
        }
        if (zeros>1){
            return vector<int>(nums.size(),0);
        }
        vector<int> answer(nums.size());
        for (int i=0; i<nums.size(); i++){
            if (zeros > 0){
                answer[i] = (nums[i] == 0) ? prod : 0;
            } else {
                answer[i] = prod / nums[i];
            }
        }
        return answer;
    }
};