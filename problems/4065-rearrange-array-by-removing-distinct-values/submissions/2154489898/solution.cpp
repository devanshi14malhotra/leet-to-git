class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int count[101] = {0};
        for (int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        vector<int> ans;
        int rem = nums.size();
        while (rem > 0){
            for (int x=1; x<=100; x++){
                if (count[x] > 0){
                    ans.push_back(x);
                    count[x]--;
                    rem--;
                }
            }
        }
        return ans;
    }
};