1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> leftSum(n);
6        leftSum[0] = 0;
7        for (int i = 1; i < n; i++) {
8            leftSum[i] = nums[i - 1] + leftSum[i - 1];
9        }
10        int count=0;
11        for (int i = n - 2; i >= 0; i--) {
12           count+=nums[i+1];
13            leftSum[i] =abs(leftSum[i]-count);
14        }
15        
16        return leftSum;
17    }
18};