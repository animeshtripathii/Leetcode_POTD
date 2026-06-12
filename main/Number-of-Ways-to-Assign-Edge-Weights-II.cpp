1class LCA {
2public:
3    LCA(const vector<vector<int>>& edges, const int root = 1) {
4        n = edges.size() + 1;
5        m = (log(n) / log(2)) + 1;
6        e.resize(n + 1);
7        d.resize(n + 1);
8        f.resize(n + 1, vector<int>(m, 0));
9        for (auto& edge : edges) {
10            int u = edge[0];
11            int v = edge[1];
12            e[u].push_back(v);
13            e[v].push_back(u);
14        }
15        dfs(root, 0);
16        for (int i = 1; i < m; i++) {
17            for (int x = 1; x <= n; x++) {
18                f[x][i] = f[f[x][i - 1]][i - 1];
19            }
20        }
21    }
22    void dfs(int x, int fa) {
23        f[x][0] = fa;
24        for (auto& y : e[x]) {
25            if (y == fa) {
26                continue;
27            }
28            d[y] = d[x] + 1;
29            dfs(y, x);
30        }
31    }
32
33    int lca(int x, int y) {
34        if (d[x] > d[y]) {
35            swap(x, y);
36        }
37        for (int i = m - 1; i >= 0; i--) {
38            if (d[x] <= d[f[y][i]]) {
39                y = f[y][i];
40            }
41        }
42        if (x == y) {
43            return x;
44        }
45        for (int i = m - 1; i >= 0; i--) {
46            if (f[y][i] != f[x][i]) {
47                x = f[x][i];
48                y = f[y][i];
49            }
50        }
51        return f[x][0];
52    }
53
54    int dis(int x, int y) { return d[x] + d[y] - d[lca(x, y)] * 2; }
55
56private:
57    int n;
58    int m;
59    vector<int> d;
60    vector<vector<int>> e;
61    vector<vector<int>> f;
62};
63
64const int MOD = 1e9 + 7;
65const int N = 100010;
66int p2[N];
67auto init = [] {
68    p2[0] = 1;
69    for (int i = 1; i < N; i++) {
70        p2[i] = p2[i - 1] * 2 % MOD;
71    }
72    return 0;
73}();
74
75class Solution {
76public:
77    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
78                                  vector<vector<int>>& queries) {
79        LCA lca(edges, 1);
80        int m = queries.size();
81        vector<int> res(m);
82        for (int i = 0; i < m; i++) {
83            int x = queries[i][0];
84            int y = queries[i][1];
85            if (x != y) {
86                res[i] = p2[lca.dis(x, y) - 1];
87            }
88        }
89        return res;
90    }
91};