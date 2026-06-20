1
2class Solution {
3public:
4    int maxBuilding(int n, vector<vector<int>>& restrictions) {
5        vector<vector<int>> arr;
6
7        arr.push_back({1, 0});
8
9        for (auto &r : restrictions) {
10            arr.push_back(r);
11        }
12        sort(arr.begin(), arr.end());
13        for (int i = 1; i < arr.size(); i++) {
14            int d = arr[i][0] - arr[i - 1][0];
15            arr[i][1] = min(arr[i][1], arr[i - 1][1] + d);
16        }
17        for (int i = arr.size() - 2; i >= 0; i--) {
18            int d = arr[i + 1][0] - arr[i][0];
19            arr[i][1] = min(arr[i][1], arr[i + 1][1] + d);
20        }
21
22        int ans = 0;
23
24        for (int i = 1; i < arr.size(); i++) {
25            int x1 = arr[i - 1][0];
26            int h1 = arr[i - 1][1];
27
28            int x2 = arr[i][0];
29            int h2 = arr[i][1];
30
31            int d = x2 - x1;
32
33            ans = max(ans, (h1 + h2 + d) / 2);
34        }
35
36        int lastPos = arr.back()[0];
37        int lastH = arr.back()[1];
38
39        ans = max(ans, lastH + (n - lastPos));
40
41        return ans;
42    }
43};