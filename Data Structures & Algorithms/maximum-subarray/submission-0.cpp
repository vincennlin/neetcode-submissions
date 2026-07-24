class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int cur = 0;

        for (int num : nums) {
            cur = max(num, cur + num);
            maxSum = max(maxSum, cur);
        }

        return maxSum;
    }
};