class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, res, cur, 0, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& res,
        vector<int>& cur, int curSum, int i, int target) {
        if (curSum == target) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            if (curSum + candidates[j] > target) break;

            cur.push_back(candidates[j]);
            dfs(candidates, res, cur, curSum + candidates[j], j + 1, target);
            cur.pop_back();
        }
    }
};