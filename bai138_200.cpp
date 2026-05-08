class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }

        return count;
    }
};

