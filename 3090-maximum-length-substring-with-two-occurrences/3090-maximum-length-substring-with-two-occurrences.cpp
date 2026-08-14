class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int>mp(26,0);
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while (j < n) {
             mp[s[j]-'a']++;
           while (mp[s[j]-'a'] > 2) {
               mp[s[i]-'a']--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};