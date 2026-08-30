class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long modd=1000000007;
        long long total=0;
        for (int i=0; i<nums.size(); i++){
            long long num = nums[i];
            int w = num%10;
            long long d = num/10;
            int totalDig = 0;
            long long temp=d;
            while (temp>0){
                totalDig++;
                temp=temp/10;
            }
            int ydig = totalDig - w;
            long long divider=1;
            for (int j=0; j<ydig; j++){
                divider = divider*10;
            }
            long long x= d/divider;
            long long y=d%divider;
            long long res=1;
            long long base=x%modd;
            long long exp = y;
            while (exp>0){
                if (exp%2==1){
                    res= (res*base)%modd;
                }
                base = (base*base) % modd;
                exp=exp/2;
            }
            total=(total+res)%modd;
        }
        return (int)total;
    }
};