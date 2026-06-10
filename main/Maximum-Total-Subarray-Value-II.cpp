1class SparseTable {
2    vector<vector<int>> Min, Max;
3
4public:
5    SparseTable(const vector<int>& num) {
6        size_t n = num.size();
7        int w = bit_width(n);
8        Min.resize(w, vector<int>(n));
9        Max.resize(w, vector<int>(n));
10
11        for (int i = 0; i < n; i++)
12            Min[0][i] = Max[0][i] = num[i];
13
14        for (int i = 1; i < w; i++)
15            for (int j = 0; j + (1 << i) <= n; j++) {
16                Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
17                Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
18            }
19    }
20
21    int query(int left, int right) {
22        int k = bit_width((uint32_t)right - left) - 1;
23        return max(Max[k][left], Max[k][right - (1 << k)]) -
24               min(Min[k][left], Min[k][right - (1 << k)]);
25    }
26};
27
28class Solution {
29public:
30    long long maxTotalValue(vector<int>& nums, int k) {
31        int n = nums.size();
32        long long res = 0;
33        SparseTable LUT(nums);
34
35        priority_queue<tuple<int, int, int>> pq;
36        for (int i = 0; i < n; i++)
37            pq.emplace(LUT.query(i, n), i, n);
38
39        while (get<0>(pq.top()) && k--) {
40            auto [val, l, r] = pq.top();
41            pq.pop();
42            res += val;
43            pq.emplace(LUT.query(l, r - 1), l, r - 1);
44        }
45
46        return res;
47    }
48};