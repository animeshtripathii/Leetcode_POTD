class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string best_str = "";
        int min_Len = INT_MAX;
        int n = s.length();
        int i = 0;
        int count = 0;
        
        for(int j = 0; j < n; j++) {
            if(s[j] == '1'){
                count++;
            }
            
            while(i <= j && (count > k || s[i] == '0')) {
                if (s[i] == '1') {
                    count--;
                }
                i++;
            }
            
            if(count == k) {
                int current_len = j - i + 1;
                string current_str = s.substr(i, current_len);
                
                if (current_len < min_Len) {
                    min_Len = current_len;
                    best_str = current_str;
                } else if (current_len == min_Len) {
                    if (current_str < best_str) {
                        best_str = current_str;
                    }
                }
            }
        }
        
        return best_str;
    }
};