class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        int INF=1000000;
        vector<int> dp(sum+1, INF);
        dp[0]=0;
        for (int i=0; i<n; i++){
            vector<int> newdp=dp;
            long long val=nums[i];
            int cost=0;
            while (val<=sum){
                for (int s=sum; s>=val; s--){
                    if (dp[s-val] + cost < newdp[s]){
                        newdp[s]=dp[s-val]+ cost;
                    }
                }
                val *= 2;
                cost++;
            }
            val=nums[i];
            cost=0;
            while (val>0){
                val=val/2;
                cost++;
                for (int s=sum; s>=val; s--){
                    if (dp[s-val]+cost<newdp[s]){
                        newdp[s]=dp[s-val]+cost;
                    }
                }
            }
            dp=newdp;
        }
        if (dp[sum] >= INF) return -1;
        return dp[sum];
    }
};