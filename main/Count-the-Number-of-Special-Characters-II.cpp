1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int n = word.size();
5        vector<int> lastSmall(26, -1);
6        vector<int> firstBig(26, -1);
7        
8        for (int i = 0; i < n; i++) {
9            if (word[i] >= 'a' && word[i] <= 'z') {
10                lastSmall[word[i] - 'a'] = i;
11            } 
12            else if (word[i] >= 'A' && word[i] <= 'Z') {
13                if (firstBig[word[i] - 'A'] == -1) {
14                    firstBig[word[i] - 'A'] = i;
15                }
16            }
17        }
18        
19        int specialCount = 0;
20        for (int i = 0; i < 26; i++) {
21            if (lastSmall[i] != -1 && firstBig[i] != -1 && lastSmall[i] < firstBig[i]) {
22                specialCount++;
23            }
24        }
25        
26        return specialCount;
27    }
28};