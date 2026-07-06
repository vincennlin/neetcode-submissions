class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    islands++;
                    dfs(grid, dirs, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& dirs, int i, int j) {
        for (auto& dir : dirs) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()
                && grid[newI][newJ] == '1') {
                grid[newI][newJ] = '0';
                dfs(grid, dirs, newI, newJ);
            }
        }
    }
};
