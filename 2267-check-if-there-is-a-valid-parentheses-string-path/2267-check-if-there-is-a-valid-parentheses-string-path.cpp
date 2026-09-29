class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int m, int n, vector<vector<char>>& grid, int count) {
        if (i > m || j > n)
            return false;

        if (grid[i][j] == ')' && count == 0)
            return false;

        if (grid[i][j] == ')')
            count--;
        else
            count++;

        if (count < 0)
            return false;

        if (i == m && j == n)
            return count == 0;

        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        bool down = solve(i + 1, j, m, n, grid, count);
        bool right = solve(i, j + 1, m, n, grid, count);

        return dp[i][j][count] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        if (grid[0][0] == ')')
            return false;

        return solve(0, 0, m - 1, n - 1, grid, 0);
    }
};