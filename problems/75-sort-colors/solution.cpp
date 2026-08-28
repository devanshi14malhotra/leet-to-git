class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for (int&num :nums){
            count[num]++;
        }
        int idx=0;
        for (int i=0; i<3; i++){
            while (count[i]-- > 0){
                nums[idx++]=i;
            }
        }
    }
};