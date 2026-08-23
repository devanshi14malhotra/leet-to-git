class Solution {
public:
    vector<int> getPrimefactors(int num){
        vector<int> primes;
        for (int p=2; p*p<=num; p++){
            if (num%p==0){
                primes.push_back(p);
                while (num%p==0){
                    num=num/p;
                }
            }
        }
        if (num>1) primes.push_back(num);
        return primes;
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int distinct=0;
        int l=0;
        int best=0;
        for (int r=0; r<nums.size(); r++){
            vector<int> primes=getPrimefactors(nums[r]);
            for (int i=0; i<primes.size(); i++){
                int p=primes[i];
                freq[p]++;
                if (freq[p]==1) distinct++;
            }
            while (distinct>k){
                vector<int> lprimes=getPrimefactors(nums[l]);
                for (int i=0; i<lprimes.size(); i++){
                    int p=lprimes[i];
                    freq[p]--;
                    if (freq[p]==0) distinct--;
                }
                l++;
            }
            int windowlen=r-l+1;
            if (windowlen>best) best=windowlen;
        }
        return best;
    }
};