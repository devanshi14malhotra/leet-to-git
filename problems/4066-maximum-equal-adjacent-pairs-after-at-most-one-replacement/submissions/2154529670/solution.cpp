class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        long long base = 0;
        unordered_map<long long, int> tcount;
        for (int i=0; i<n-1; i++){
            int a = nums[i];
            int b = nums[i+1];
            if (a==b){
                base++;
            } else {
                int l= min(a,b);
                int h= max(a,b);
                long long key = (long long)l * 2000000000LL + h;
                tcount[key]++;
            }
        }
        int best=0;
        for (pair<long long, int> entry:tcount){
            best = max(best,entry.second);
        }
        return (int)(base+best);
    }
};