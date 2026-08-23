class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
    
    for (int i = 0; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (result.size() == 0) {
            result.push_back(intervals[i]);
        } else {
            int lastIndex = result.size() - 1;
            int lastEnd = result[lastIndex][1];
                if (start > lastEnd) {
                    result.push_back(intervals[i]);
                } else {
                    if (end > lastEnd) {
                    result[lastIndex][1] = end;
                }
            }
        }
    }
    return result;
    }
};

