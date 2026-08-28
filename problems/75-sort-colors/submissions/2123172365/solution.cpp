class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        for (int two=0; two<n; two++){
            int temp=nums[two];
            nums[two]=2;
            if (temp<2){
                nums[one++]=1;
            }
            if (temp<1){
                nums[zero++]=0;
            }
        }
    }
};