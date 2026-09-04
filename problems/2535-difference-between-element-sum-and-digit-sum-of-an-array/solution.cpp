class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int el_sum=0;
        int dig_sum=0;
        for (int i=0; i<nums.size(); i++){
            int num = nums[i];
            el_sum = el_sum + num;
            while (num>0){
                dig_sum = dig_sum + (num%10);
                num= num/10;
            }
        }
        return abs(el_sum - dig_sum);
    }
};