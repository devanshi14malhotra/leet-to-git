class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0; 
        int r=1;
        int maxp=0;
        while (r<prices.size()){
            if (prices[l]<prices[r]){
                int prof = prices[r]-prices[l];
                maxp=max(maxp,prof);
            } else {
                l = r;
            }
            r++;
        }
        return maxp;
    }
};