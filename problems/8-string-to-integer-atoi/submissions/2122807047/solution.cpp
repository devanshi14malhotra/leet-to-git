class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while (i<n && s[i]==' ') i++; //skip spaces
        int sign=1; // assume sign +ve
        if (i<n && s[i]=='+' || s[i] == '-'){ 
            //but check for -ve SPECIFICALLY
            if (i<n && s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long res= readdig(s,i,n,0);
        res=res*sign; //applying sign
        
        //clamp to 32bit range
        if (res>INT_MAX) return INT_MAX;
        if (res<INT_MIN) return INT_MIN;
        return (int)res;
    }
    long readdig(string&s, int i, int n, long res){
        // base case - stop when end of string or curr char is not dig
        if (i>=n || s[i]<'0' || s[i]>'9'){
            return res;
        }
        if (res>INT_MAX){
            return readdig(s,i+1,n,res);
        }

        //multiply if safe, or else overflow
        // IMP! 
        res=res*10+(s[i]-'0'); // add curr dig to res, s[i]-'0' converts char to int as char hv ascii val

        return readdig(s,i+1,n,res); // RECURSION for processing next char

    }
};