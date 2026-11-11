class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        long long ans = n1 * c1 + n2 * c2;          

        long long lo = min(n1, n2);
        long long extraCost = (n1 > n2) ? c1 : c2;   
        long long rest = abs(n1 - n2);

        ans = min(ans, lo * cb + rest * extraCost); 
        ans = min(ans, max(n1, n2) * cb);           
        return ans;
    }
};