class Solution {
public:
    int dist(int a, int b){
        int d= abs(a-b);
        return min(d,10-d);
    }
    int minRotations(int n, string s) {
        vector<int> d(n);
        for (int i=0; i<n; i++) d[i]=s[i]-'0';
        int tot= dist(0,d[0]);
        for (int i=0; i+1<n; i++) tot+= dist(d[i],d[i+1]);
        int ans=tot;
        ans=min(ans,dist(0,d[n-1]) + (tot - dist(0,d[0])));
        for (int k=1; k<n; k++){
            int newc = tot - dist(d[k-1],d[k]) + dist(d[k-1],d[n-1]);
            ans=min(ans,newc);
        }
        return ans;
    }
};