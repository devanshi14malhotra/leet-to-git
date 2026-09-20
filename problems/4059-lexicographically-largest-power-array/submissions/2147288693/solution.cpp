class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<int> power(15,0);
        vector<vector<int>> blocks;
        blocks.push_back(nums);
        for (int bit=14; bit>=0; bit--){
            int total = 0;
            for (int idx = 0; idx<blocks.size(); idx++){
                vector<int> withbit;
                vector<int> withoutbit;
                for (int k=0; k<blocks[idx].size(); k++){
                    if ((blocks[idx][k] >> bit) & 1){
                        withbit.push_back(blocks[idx][k]);
                    } else {
                        withoutbit.push_back(blocks[idx][k]);
                    }
                }
                total += withbit.size();
                if (withoutbit.empty()) continue;
                if (!withbit.empty()){
                    blocks[idx] = withbit;
                    blocks.insert(blocks.begin() + idx+1, withoutbit);
                }
                break;
            }
            power[14-bit] = total;
        }
        return power;
    }
};