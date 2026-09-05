class Solution {
public:
    bool winnerOfGame(string colors) {
        int al = 0;
        int bob = 0;
        for (int i=1; i<colors.size(); i++){
            if (colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if (colors[i]=='A') al++;
                else bob++;
            }
        }
        return al>bob;
    }
};