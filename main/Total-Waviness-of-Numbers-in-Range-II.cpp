1class Solution {
2public:
3    using ll = long long;
4
5    struct State {
6        int prev, curr, tight, lead;
7        ll cnt, sum;
8    };
9
10    ll solve(ll num) {
11        // if the number has fewer than 3 digits, the fluctuation value is 0
12        if (num < 100) {
13            return 0;
14        }
15        string s = to_string(num);
16        int n = s.size();
17
18        vector<State> currStates;
19        // digit 10 indicates the invalid invalid state when there are leading
20        // zeros
21        currStates.push_back({10, 10, 1, 1, 1, 0});
22        for (int pos = 0; pos < n; ++pos) {
23            int limit = s[pos] - '0';
24            ll cnt[2][2][11][11] = {0};
25            ll sum[2][2][11][11] = {0};
26
27            for (const auto& st : currStates) {
28                int maxDigit = st.tight ? limit : 9;
29                for (int digit = 0; digit <= maxDigit; ++digit) {
30                    int newLead = st.lead && (digit == 0);
31                    int newPrev = st.curr;
32                    int newCurr = newLead ? 10 : digit;
33                    int newTight = st.tight && (digit == maxDigit);
34
35                    ll add = 0;
36                    // calculate fluctuation only when there are three
37                    // significant digits (both prev and curr are valid and not
38                    // leading zeros)
39                    if (!newLead && st.prev != 10 && st.curr != 10) {
40                        if ((st.prev < st.curr && st.curr > digit) ||
41                            (st.prev > st.curr && st.curr < digit)) {
42                            add = st.cnt;
43                        }
44                    }
45
46                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
47                    sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
48                }
49            }
50
51            // collect legal states
52            vector<State> nextStates;
53            for (int tight = 0; tight < 2; ++tight) {
54                for (int lead = 0; lead < 2; ++lead) {
55                    for (int prev = 0; prev <= 10; ++prev) {
56                        for (int curr = 0; curr <= 10; ++curr) {
57                            ll c = cnt[tight][lead][prev][curr];
58                            ll s = sum[tight][lead][prev][curr];
59                            // if the current state is valid, proceed to the
60                            // next round of calculation
61                            if (c != 0) {
62                                nextStates.push_back(
63                                    {prev, curr, tight, lead, c, s});
64                            }
65                        }
66                    }
67                }
68            }
69
70            currStates.swap(nextStates);
71        }
72
73        // sum of fluctuation values of all valid states
74        ll ans = 0;
75        for (const auto& st : currStates) {
76            ans += st.sum;
77        }
78        return ans;
79    }
80
81    long long totalWaviness(long long num1, long long num2) {
82        return solve(num2) - solve(num1 - 1);
83    }
84};