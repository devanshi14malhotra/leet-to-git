class Solution {
public:
// brent's algo
    int sumofSq(int n){
        int output=0;
        while (n!=0){
            int lastdig=n%10;
            lastdig = lastdig*lastdig;
            output+=lastdig;
            n=n/10;
        }
        return output;
    }

    bool isHappy(int n) {
        int slow=n; // fixed ref ptr - stays at same pos b4 being updated
        int fast=sumofSq(n); // moving ptr-moves fwd 1 step after every iteration
        int power=1; // how many steps we will let 'fast' move b4 updating slow (1,2,4,8,16)
        int lam=1; // no. of steps 'fast' has taken since slow was updated

        while (slow!=fast){ // stop when both ptrs at same value
            if (power==lam){ // hv we let 'fast' move enuff steps?
                slow=fast; // move ref ptr to fast's curr pos
                power*=2; // next time, wait twice as long b4 updating slow again
                lam=0; // restart counting steps from 0
            }
            lam++; // 'fast' is abt to move one step
            fast=sumofSq(fast); // move fast fwd by 1 transformation
        }
        return fast==1; // happy no. if meeting pt is 1
    }
};