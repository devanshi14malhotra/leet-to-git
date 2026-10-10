class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> arr; 
        for (int i = 0; i < n; i++) {
            arr.push_back(make_pair(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        int bestProduct = 0;
        bool found = false;
        int bi = -1, bj = -1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                if (arr[right].first > arr[left].first) {
                    int product = arr[right].first * arr[left].first;
                    if (!found || product > bestProduct) {
                        found = true;
                        bestProduct = product;
                        bi = arr[right].second; 
                        bj = arr[left].second; 
                    }
                }
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        vector<int> ans;
        ans.push_back(bi);
        ans.push_back(bj);
        return ans;
    }
};