class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (int x:nums2){
            if (set1.count(x)){
                result.insert(x);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};