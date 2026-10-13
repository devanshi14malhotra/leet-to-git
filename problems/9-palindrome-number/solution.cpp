class Solution {
public:
    bool isPalindrome(int x) {
        int revn=0;
        int dup=x;
        while (x>0){
            int lastd=x%10;
            if (revn > INT_MAX/10 || revn < INT_MIN/10) return 0; 
            revn=(revn*10)+lastd;
            x=x/10;
        }
        if (dup==revn) return true;
        else return false;
    }
};