1class SegmentTree {
2    int n;
3    vector<int> tree;
4
5public:
6    SegmentTree(int n) {
7        this->n = n;
8        tree.assign(4 * n, 0);
9    }
10
11    void update(int node, int start, int end, int idx, int val) {
12        if (start == end) {
13            tree[node] = val;
14            return;
15        }
16        int mid = start + (end - start) / 2;
17        if (idx <= mid) {
18            update(2 * node, start, mid, idx, val);
19        } else {
20            update(2 * node + 1, mid + 1, end, idx, val);
21        }
22        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
23    }
24
25    int query(int node, int start, int end, int l, int r) {
26        if (r < start || end < l) {
27            return 0;
28        }
29        if (l <= start && end <= r) {
30            return tree[node];
31        }
32        int mid = start + (end - start) / 2;
33        return max(query(2 * node, start, mid, l, r),
34                   query(2 * node + 1, mid + 1, end, l, r));
35    }
36};
37
38class Solution {
39public:
40    vector<bool> getResults(vector<vector<int>>& queries) {
41        int max_x = 0;
42        for (const auto& q : queries) {
43            max_x = max(max_x, q[1]);
44        }
45       
46        int M = max(50000, max_x) + 1;
47
48        SegmentTree st(M);
49        set<int> obstacles;
50        obstacles.insert(0);
51        obstacles.insert(M); 
52        st.update(1, 0, M - 1, M, M); 
53
54        vector<bool> result;
55
56        for (const auto& query : queries) {
57            int type = query[0];
58            int x = query[1];
59
60            if (type == 1) {
61                auto it = obstacles.upper_bound(x);
62                int next_obs = *it;
63                int prev_obs = *prev(it);
64
65                obstacles.insert(x);
66                st.update(1, 0, M - 1, x, x - prev_obs);
67                st.update(1, 0, M - 1, next_obs, next_obs - x);
68            } 
69            else if (type == 2) {
70                int sz = query[2];
71                auto it = obstacles.upper_bound(x);
72                int prev_obs = *prev(it);
73                int max_gap_before = st.query(1, 0, M - 1, 0, prev_obs);
74                int last_gap = x - prev_obs;
75
76                if (max(max_gap_before, last_gap) >= sz) {
77                    result.push_back(true);
78                } else {
79                    result.push_back(false);
80                }
81            }
82        }
83
84        return result;
85    }
86};