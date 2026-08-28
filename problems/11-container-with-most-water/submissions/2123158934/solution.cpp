class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int res=0;
        while (l<r){
            int area=min(height[l],height[r]) * (r-l);
            res=max(res,area);
            if (height[l]<=height[r]){
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};