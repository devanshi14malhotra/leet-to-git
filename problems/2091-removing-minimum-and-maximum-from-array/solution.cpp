class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = min_element(nums.begin(), nums.end()) - nums.begin();
        int j = max_element(nums.begin(), nums.end()) - nums.begin();
        if (i > j) swap(i, j);

        int fromFront = j + 1;             
        int fromBack  = n - i;          
        int mixed     = (i + 1) + (n - j); 
        return min({fromFront, fromBack, mixed});
    }
};