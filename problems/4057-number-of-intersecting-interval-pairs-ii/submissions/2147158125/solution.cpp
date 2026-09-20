class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ends;
        for (int i=0; i<n; i++){
            ends.push_back(intervals[i][1]);
        }
        sort(ends.begin(), ends.end());
        long long nonintersect = 0;
        for (int j=0; j<n; j++){
            int start = intervals[j][0];
            nonintersect += lower_bound(ends.begin(), ends.end(), start) - ends.begin();
        }
        long long totalpairs = (long long)n*(n-1)/2;
        return totalpairs - nonintersect;
    }
};