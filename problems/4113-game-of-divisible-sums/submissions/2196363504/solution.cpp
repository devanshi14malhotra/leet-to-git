class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n=nums.size();
        long long n1=0, n2=0;
        for (int i=n-1; i>=0; i--){
            long long s=nums[i];
            long long cur = (s%3==0) ? s-n1 : s+n1;
            if (i+1<n){
                s += nums[i+1];
                long long two= (s%3==0) ? s-n2 : s+n2;
                cur = max(cur,two);
            }
            n2=n1;
            n1=cur;
        }
        return n1;
    }
};