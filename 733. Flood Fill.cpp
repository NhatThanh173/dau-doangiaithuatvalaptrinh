class Solution {
public:
    int rows, cols;
    int oldColor, newColor;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& image, int r, int c) {

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (image[r][c] != oldColor) {
            return;
        }

        image[r][c] = newColor;

        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            dfs(image, nr, nc);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        rows = image.size();
        cols = image[0].size();
        oldColor = image[sr][sc];
        newColor = color;

        if (oldColor == newColor) {
            return image;
        }

        dfs(image, sr, sc);
        return image;
    }
};

