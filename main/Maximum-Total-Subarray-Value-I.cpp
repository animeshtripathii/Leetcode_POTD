1class Solution {
2public:
3    static long long maxTotalValue(vector<int>& nums, int k) {
4        auto [m, M]=minmax_element(nums.begin(), nums.end());
5        return (long long)k*(*M-*m);
6    }
7};