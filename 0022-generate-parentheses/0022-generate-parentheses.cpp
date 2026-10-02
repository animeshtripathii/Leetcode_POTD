class Solution {
private:
    void backtrack(int n, int open_count, int close_count, string current_string, vector<string>& result) {
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }
        
        if (open_count < n) {
            backtrack(n, open_count + 1, close_count, current_string + "(", result);
        }
        
        if (close_count < open_count) {
            backtrack(n, open_count, close_count + 1, current_string + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};