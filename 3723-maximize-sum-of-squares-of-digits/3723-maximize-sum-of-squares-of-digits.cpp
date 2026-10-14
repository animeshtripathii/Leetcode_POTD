
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
    
        if (sum == 0 || sum > 9 * num) {
            return "";
        }

        string res;
        while (num > 0) {
            int digit = min(9, sum);

            res.push_back(char('0' + digit));
            sum -= digit;
            num--;
        }
        if (sum > 0) {
            return "";
        }

        return res;
    }
};