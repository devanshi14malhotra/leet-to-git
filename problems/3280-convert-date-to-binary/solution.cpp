class Solution {
public:
    string toBinary(int n){
        if (n == 0) return "0";
        string res = "";
        while (n != 0){
            int r = n % 2;
            res += ('0' + r);
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string convertDateToBinary(string date) {
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        return toBinary(y) + "-" + toBinary(m) + "-" + toBinary(d);
    }
};