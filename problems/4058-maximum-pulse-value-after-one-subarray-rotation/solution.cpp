class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 0;
        long long minsum = 0;
        long long maxpref[2] = {0, LLONG_MIN};
        for (int j=1; j<=n; j++){
            if ((j-1)%2 == 0){
                prefix += nums[j-1];
            } else {
                prefix -= nums[j-1];
            }
            int p = j % 2;
            if (maxpref[p] != LLONG_MIN){
                minsum = min(minsum, prefix - maxpref[p]);
            }
            maxpref[p] = max(maxpref[p], prefix);
        }
        long long pulse = prefix;
        return pulse - 2*minsum;
    }
};