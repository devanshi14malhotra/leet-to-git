class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int first[101];
        int last[101];
        int count[101];
        for (int i=0; i<=100; i++) count[i]=0;
        for (int i=0; i<nums.size();i++){
            int val=nums[i];
            if (count[val]==0){
                first[val]=i;
            }
            last[val]=i;
            count[val]++;
        }
        int res=0;
        for (int val=1; val<=100; val++){
            if (count[val]>0){
                int blocksize=last[val]-first[val]+1;
                if (blocksize==count[val]){
                    res++;
                }
            }
        }
        return res;
    }
};