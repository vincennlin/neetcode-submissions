class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int curArea = 0;
                    dfs(grid, i, j, &curArea);
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int* curArea) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }

        (*curArea)++;
        grid[i][j] = 0;

        for (auto& dir : dirs) {
            dfs(grid, i + dir[0], j + dir[1], curArea);
        }
    }
};