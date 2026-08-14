class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, ans=0;
        int n=s.length();
        unordered_map<char,int> freq;
        for (int r=0;r<n;r++){
            freq[s[r]]++;

            while (freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};