class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> exists;
        for (int num:nums){
            if (exists.count(num)) return true;
            exists.insert(num);
        }
        return false;
    }
};