class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxl = 0;
        for (int i=0; i<n; i++){
            long long sum = 0;
            unordered_map<int,int> keycount;
            for (int j=i; j<n; j++){
                sum += nums[j];
                long long ek = (2LL * nums[j]) % k;
                if (ek < 0) ek += k;
                keycount[(int)ek]++;
                long long summod = sum % k;
                if (summod < 0) summod += k;
                bool valid= false;
                if (summod == 0){
                    valid=true;
                } else if (keycount.find((int)summod) != keycount.end()){
                    valid=true;
                }
                if (valid){
                    maxl = max(maxl, j-i+1);
                }
            }
        }
        return maxl;
    }
};