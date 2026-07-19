class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        vector<bool> visited(26, false);
        string stack = "";

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (visited[curr - 'a']) {
                continue;
            }

            while (!stack.empty() && curr < stack.back() && lastIndex[stack.back() - 'a'] > i) {
                visited[stack.back() - 'a'] = false; 
                stack.pop_back();                   
            }


            stack.push_back(curr);
            visited[curr - 'a'] = true;
        }

        return stack;
    }
};