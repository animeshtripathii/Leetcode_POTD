1class Solution {
2public:
3    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
4        unordered_set<int> prefixes;
5        
6        for (int val : arr1) {
7            while (val > 0) {
8                prefixes.insert(val);
9                val /= 10;
10            }
11        }
12        
13        int maxLength =0;
14        
15        for (int val : arr2) {
16            while (val > 0) {
17                if (prefixes.count(val)) {
18                    int currentLength = to_string(val).length();
19                    maxLength = max(maxLength, currentLength);
20                    break;
21                }
22                val /= 10;
23            }
24        }
25        
26        return maxLength;
27    }
28};