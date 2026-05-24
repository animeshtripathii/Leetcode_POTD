1class Solution {
2public:
3    int n;
4
5    int dfs(int i,vector<int>& arr,int d,vector<int>& dp) {
6
7        if(dp[i] != -1) {
8            return dp[i];
9        }
10
11        int ans = 1;
12
13        // move right
14        for(int j = i + 1;j <= min(n - 1, i + d);j++) {
15            // blocked
16            if(arr[j] >= arr[i]) {
17                break;
18            }
19
20            ans = max(ans,1 + dfs(j, arr, d, dp));
21        }
22
23        // move left
24        for(int j = i - 1;j >= max(0, i - d);j--) {
25            // blocked
26            if(arr[j] >= arr[i]) {
27                break;
28            }
29
30            ans = max(ans,1 + dfs(j, arr, d, dp));
31        }
32
33        return dp[i] = ans;
34    }
35
36    int maxJumps(vector<int>& arr, int d) {
37        n = arr.size();
38
39        vector<int> dp(n, -1);
40        int ans = 1;
41
42        for(int i = 0; i < n; i++) {
43            ans = max(ans,dfs(i, arr, d, dp));
44        }
45
46        return ans;
47    }
48};