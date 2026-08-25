class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int minb=prices[0];
        for (int& sell:prices){
            maxp= max(maxp, sell-minb);
            minb=min(minb,sell);
        }
        return maxp;
    }
};