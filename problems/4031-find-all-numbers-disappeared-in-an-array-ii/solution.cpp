class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> present;
        for (int i=0; i<nums.size(); i++){
            present.insert(nums[i]);
        }
        vector<vector<int>> result;
        int num=lower;
        while (num<=upper){
            if (present.count(num)==0){
                int start=num;
                while (num <= upper && present.count(num)==0){
                    num=num+1;
                }
                int end=num-1;
                vector<int> range;
                range.push_back(start);
                range.push_back(end);
                result.push_back(range);
            } else {
                num=num + 1;
            }
        }
        return result;
    }
};