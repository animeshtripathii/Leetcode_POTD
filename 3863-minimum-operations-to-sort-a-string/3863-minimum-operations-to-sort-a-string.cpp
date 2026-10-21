class Solution {
public:
    int minOperations(string s) {
        string sorunavile = s; 
        int n = s.length();
        
        bool is_sorted_str = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i+1]) {
                is_sorted_str = false;
                break;
            }
        }
        if (is_sorted_str) return 0;
        
        if (n < 3) return -1;
        
        char max_pref = s[0];
        char min_pref = s[0];
        for (int i = 1; i < n - 1; i++) {
            max_pref = max(max_pref, s[i]);
            min_pref = min(min_pref, s[i]);
        }
        
        char max_suff = s[1];
        char min_suff = s[1];
        for (int i = 2; i < n; i++) {
            max_suff = max(max_suff, s[i]);
            min_suff = min(min_suff, s[i]);
        }
        
        if (max_pref <= s[n - 1] || s[0] <= min_suff) {
            return 1;
        }
        
        if (min_pref <= s[n - 1] || s[0] <= max_suff) {
            return 2;
        }
        
        return 3;
    }
};