class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx=target[0], ty=target[1];
        int minDist = 101;
        int bestidx = -1;
        for (int i=0; i<drones.size(); i++){
            int xi = drones[i][0];
            int yi = drones[i][1];
            int ri= drones[i][2];
            int manhat = abs(xi-tx)+abs(yi-ty);
            if (manhat <= ri && manhat < minDist){
                minDist = manhat;
                bestidx = i;
            }
        }
        return bestidx;
    }
};