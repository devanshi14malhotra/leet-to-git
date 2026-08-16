class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxLight = 0;
        for (int i = 0; i < lights.size(); i++) {
            if (lights[i] > maxLight) maxLight = lights[i];
        }
        int maxwait = 0;
        for (int j = 0; j < arrivalTime.size(); j++) {
            int r = arrivalTime[j] % period;
            int wait;
            if (r < maxLight) wait = 0;
            else wait = period - r;
            if (wait > maxwait) maxwait = wait;
        }
        return maxwait;
    }
};