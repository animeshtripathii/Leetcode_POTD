1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4        int n = s.size();
5        if (s[n - 1] == '1') return false;
6
7        vector<bool> visited(n, false);
8        queue<int> q;
9        
10        q.push(0);
11        visited[0] = true;
12        int far_reached = 0;
13
14        while (!q.empty()) {
15            int i = q.front();
16            q.pop();
17
18            if (i == n - 1) return true;
19
20            int start = max(i + minJump, far_reached + 1);
21            int end = min(i + maxJump, n - 1);
22
23            for (int j = start; j <= end; j++) {
24                if (!visited[j] && s[j] == '0') {
25                    q.push(j);
26                    visited[j] = true;
27                }
28            }
29            far_reached = max(far_reached, i + maxJump);
30        }
31        return false;
32    }
33};