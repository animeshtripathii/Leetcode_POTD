class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix_sum(n, 0);
        suffix_sum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        function<int(int, int)> dfs = [&](int i, int M) {
            if (i >= n) {
                return 0;
            }
            if (i + 2 * M >= n) {
                return suffix_sum[i];
            }
            if (memo[i][M] != -1) {
                return memo[i][M];
            }
            
            int max_stones = 0;
            for (int x = 1; x <= 2 * M; ++x) {
                int current_stones = suffix_sum[i] - dfs(i + x, max(M, x));
                max_stones = max(max_stones, current_stones);
            }
            
            return memo[i][M] = max_stones;
        };
        return dfs(0, 1);
    }
};