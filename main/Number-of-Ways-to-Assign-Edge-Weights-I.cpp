1class Solution {
2public:
3    int MOD = 1e9 + 7;
4
5    long long modPow(long long base, long long exp) {
6        long long res = 1;
7        base = base % MOD;
8        while (exp > 0) {
9            if (exp % 2 == 1) {
10                res = (res * base) % MOD;
11            }
12            base = (base * base) % MOD;
13            exp /= 2;
14        }
15        return res;
16    }
17
18    int assignEdgeWeights(vector<vector<int>>& edges) {
19        int n = edges.size() + 1; 
20        
21        if (n == 1) return 0;
22
23        vector<vector<int>> adj(n + 1);
24        for (auto& edge : edges) {
25            adj[edge[0]].push_back(edge[1]);
26            adj[edge[1]].push_back(edge[0]);
27        }
28
29        int maxDepth = 0;
30        queue<pair<int, int>> q;
31        vector<bool> visited(n + 1, false);
32        
33        q.push({1, 0});
34        visited[1] = true;
35
36        while (!q.empty()) {
37            auto [node, depth] = q.front();
38            q.pop();
39
40            maxDepth = max(maxDepth, depth);
41
42            for (int neighbor : adj[node]) {
43                if (!visited[neighbor]) {
44                    visited[neighbor] = true;
45                    q.push({neighbor, depth + 1});
46                }
47            }
48        }
49
50        if (maxDepth == 0) return 0;
51        return modPow(2, maxDepth - 1);
52    }
53};