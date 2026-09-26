class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string result = "";
        string current_key = "";
        bool in_bracket = false;

        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } 
            else if (c == ')') {
                in_bracket = false; 
                
                if (mp.count(current_key)) {
                    result += mp[current_key];
                } else {
                    result += "?";
                }
                
                current_key = ""; 
            } 
            else {
                if (in_bracket) {
                    current_key += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};