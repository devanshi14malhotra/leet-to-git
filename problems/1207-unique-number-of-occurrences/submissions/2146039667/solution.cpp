class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int i = 0; i < arr.size(); i++) {
            count[arr[i]]++;
        }

        unordered_set<int> seen;
        for (pair<int, int> p : count) {
            if (seen.count(p.second) == 1) {
                return false;
            }
            seen.insert(p.second);
        }
        return true;
    }
};