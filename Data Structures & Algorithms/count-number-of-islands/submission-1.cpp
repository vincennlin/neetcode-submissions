class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        for (auto& dir : dirs) {
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }
};
