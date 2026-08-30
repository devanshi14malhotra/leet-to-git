class Solution {
public:
    int getgcd(int a, int b){
        while (b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int best=0;
        for (int r=-1; r<n; r++){
            vector<int> arr;
            arr.reserve(n);
            for (int j=0; j<n; j++){
                if (j!=r) arr.push_back(nums[j]);
            }
            int m=arr.size();
            if (m<2) continue;
            vector<int> pre(m), suf(m);
            pre[0]=arr[0];
            for (int i=1; i<m; i++){
                pre[i]=getgcd(pre[i-1],arr[i]);
            }
            suf[m-1]=arr[m-1];
            for (int i=m-2; i>=0; i--){
                suf[i]=getgcd(suf[i+1],arr[i]);
            }
            int count=0;
            for (int i=0; i<m-1; i++){
                if (pre[i]==suf[i+1]) count++;
            }
            best=max(best,count);
        }
        return best;
    }
};