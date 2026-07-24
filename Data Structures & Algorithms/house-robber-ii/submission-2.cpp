class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(helper(vector<int>(nums.begin() + 1, nums.end())),
                    helper(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int helper(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int rob1 = nums[0];
        int rob2 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int newRob = max(rob2, rob1 + nums[i]);
            rob1 = rob2;
            rob2 = newRob;
        }

        return rob2;
    }
};