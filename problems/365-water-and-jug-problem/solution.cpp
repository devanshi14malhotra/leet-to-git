class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return (target <= x+y) && target % gcd(x,y)==0;
    }
};