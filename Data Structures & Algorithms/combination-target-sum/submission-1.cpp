class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0, 0, target);
        return res;
    }

    void dfs(const vector<int>& nums, vector<vector<int>>& res,
        vector<int>& cur, int curSum, int i, int target) {
        if (curSum == target) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (curSum + nums[j] > target) {
                return;
            }
            cur.push_back(nums[j]);
            dfs(nums, res, cur, curSum + nums[j], j, target);
            cur.pop_back();
        }
    }
};
