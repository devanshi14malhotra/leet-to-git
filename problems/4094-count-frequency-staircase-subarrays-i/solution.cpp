class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for (int i=0; i<n; i++){
            unordered_map<int,int> count,pos;
            int k=0, matches=0;
            for (int j=i; j<n; j++){
                int v = nums[j];
                if (count[v] == 0){
                    pos[v] = k;
                    k++;
                    count[v] = 1;
                    if (pos[v] == 0) matches++;
                } else {
                    int f=count[v];
                    int p=pos[v];
                    if (f>p) break;
                    if (f == p+1) matches--;
                    count[v]++;
                    if (f==p) matches++;
                }
                if (matches==k) ans++;
            }
        }
        return ans;
    }
};