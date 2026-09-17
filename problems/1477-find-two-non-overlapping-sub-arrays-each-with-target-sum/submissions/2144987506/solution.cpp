class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX); // best[i] = min length of a valid subarray ending at or before i

        int left = 0, sum = 0;
        int ans = INT_MAX;
        int bestSoFar = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + len);
                }

                bestSoFar = min(bestSoFar, len);
            }

            best[right] = bestSoFar;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};