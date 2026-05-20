1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5        vector<int> ans(n, 0);
6        vector<int> freq(n + 1, 0);
7        int common_count = 0;
8
9        for (int i = 0; i < n; i++) {
10            freq[A[i]]++;
11            if (freq[A[i]] == 2) {
12                common_count++;
13            }
14
15            freq[B[i]]++;
16            if (freq[B[i]] == 2) {
17                common_count++;
18            }
19
20            ans[i] = common_count;
21        }
22
23        return ans;
24    }
25};