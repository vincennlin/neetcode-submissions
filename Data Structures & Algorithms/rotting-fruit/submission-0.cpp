class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int minute = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (fresh > 0 && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto& dir : dirs) {
                    int r = row + dir[0];
                    int c = col + dir[1];

                    if (r < 0 || r >= m || c < 0 || c >= n
                        || grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                }
            }
            minute++;
        }

        return fresh == 0 ? minute : -1;
    }
};
