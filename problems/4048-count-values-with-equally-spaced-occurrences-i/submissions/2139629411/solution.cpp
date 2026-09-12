class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count[101];
        int firstidx[101];
        int secidx[101];
        int lastidx[101];
        for (int i=0; i<=100; i++){
            count[i] = 0;
            firstidx[i] = -1;
            secidx[i] = -1;
            lastidx[i] = -1;
        }
        for (int i=0; i<nums.size(); i++){
            int val = nums[i];
            count[val]++;
            if (count[val]==1) firstidx[val] = i;
            if (count[val]==2) secidx[val] = i;
            if (count[val]==3) lastidx[val] = i;
        }
        int res=0;
        for (int val = 1; val<=100; val++){
            if (count[val] == 3){
                int g1 = secidx[val] - firstidx[val];
                int g2 = lastidx[val] - secidx[val];
                if (g1 == g2) res++;
            }
        }
        return res;
    }
};