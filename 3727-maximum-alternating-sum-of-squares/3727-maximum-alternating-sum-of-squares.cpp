class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);

        for (int i = 0; i < n; ++i) {
            squares[i] = (long long)nums[i] * nums[i];
        }

        sort(squares.begin(), squares.end());

        int left = 0;
        int right = n - 1;
        long long score = 0;

        while (left < right) {
            score += (squares[right] - squares[left]);
            left++;
            right--;
        }

        if (left == right) {
            score += squares[left];
        }

        return score;
    }
};