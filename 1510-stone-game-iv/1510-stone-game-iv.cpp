class Solution {
private:
    bool can_win(int remain, std::vector<int>& memo) {
        if (remain == 0) {
            return false;
        }
        
        if (memo[remain] != -1) {
            return memo[remain] == 1;
        }
        
        for (int k = 1; k * k <= remain; ++k) {
            if (!can_win(remain - k * k, memo)) {
                memo[remain] = 1;
                return true;
            }
        }
        
        memo[remain] = 0;
        return false;
    }

public:
    bool winnerSquareGame(int n) {
        std::vector<int> memo(n + 1, -1);
        return can_win(n, memo);
    }
};