1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<bool> lowerSeen(26, false);
5        vector<bool> upperSeen(26, false);
6        
7        for (char c : word) {
8            if (islower(c)) {
9                lowerSeen[c - 'a'] = true;
10            } else if (isupper(c)) {
11                upperSeen[c - 'A'] = true;
12            }
13        }
14        
15        int specialCount = 0;
16        for (int i = 0; i < 26; i++) {
17            if (lowerSeen[i] && upperSeen[i]) {
18                specialCount++;
19            }
20        }
21        
22        return specialCount;
23    }
24};