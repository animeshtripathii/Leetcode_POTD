class Solution {
public:
    int m, n;
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        if (r >= m || r < 0 || c >= n || c < 0) {
            return false;
        }
        if (grid[r][c] == 1) {
            return true;
        }
        grid[r][c] = 1;
        int left_closed = dfs(r, c - 1, grid);
        int right_closed = dfs(r, c + 1, grid);
        int up_closed = dfs(r - 1, c, grid);
        int down_closed = dfs(r + 1, c, grid);
        return left_closed && right_closed && up_closed && down_closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) 
                    if (dfs(i, j, grid) == true) {
                        count++;
                    }
                
            }
        }
        return count;
    }
};