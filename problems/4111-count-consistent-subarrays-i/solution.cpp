class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size(), count=0;
        for (int st=0; st<n; st++){
            for (int en=st; en<n; en++){
                int andv = nums[st], minv = nums[st];
                for (int k=st; k<=en; k++){
                    andv = andv & nums[k];
                    minv = min(minv, nums[k]);
                }
                if (andv == minv) count++;
            }
        }
        return count;
    }
};