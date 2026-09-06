class Solution {
public:
    int countRotations(string s, int k) {
      int n=s.size();
        int count=0;
        for (int r=0; r<n; r++){
            string rot = s.substr(r) + s.substr(0,r);
            int score = 0;
            for (int i=0; i<n; i++){
                if (rot[i] == rot[i+1]) score++;
            }
            if (score==k) count++;
        }
        return count;
    }
};