1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int ans = 0, sum = 0;
5
6        for (auto& it : gain) {
7            sum += it;
8            int d = sum - ans;
9            ans += d & ~(d >> 0x1F);
10        }
11
12        return ans;
13    }
14};