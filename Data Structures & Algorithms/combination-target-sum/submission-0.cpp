class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0, target);
        return res;
    }

    void dfs(const vector<int>& nums, vector<vector<int>>& res,
        vector<int>& cur, int i, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (i >= nums.size() || target < 0) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, res, cur, i, target - nums[i]);
        cur.pop_back();
        dfs(nums, res, cur, i + 1, target);
    }
};
