class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res = "";
        while (n!=0){
            int r = n & 1; //checks last bin bit of n → r=0 means n even, 1 means odd
            res += ('0' + r);
            n -= r;
            n /= -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
class Solution {
public:
    string decimalToBinary(int n) {
        if (n == 0) return "0";
        string result = "";
        while (n != 0) {
            int r = n % 2;
            result += ('0' + r);
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
*/