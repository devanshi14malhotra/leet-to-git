class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> pos;
        for (int i=0; i<nums.size(); i++){
            int val = nums[i];
            pos[val].push_back(i);
        }
        int res = 0;
        for (pair<const int, vector<int>> entry : pos){
            vector<int> p = entry.second;
            int tot = p.size();
            if (tot >= 3){
                int gap = p[1] - p[0];
                bool ok = true;
                for (int i = 2; i<tot; i++){
                    int currg = p[i] - p[i-1];
                    if (currg != gap){
                        ok = false;
                        break;
                    }
                }
                if (ok) res++;
            }
        }
        return res;
    }
};