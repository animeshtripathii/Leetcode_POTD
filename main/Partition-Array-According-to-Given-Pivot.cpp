1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        int n = nums.size();
5        vector<int> ans(n);
6        
7        int left = 0;
8        int right = n - 1;
9        for (int i = 0, j = n - 1; i < n; i++, j--) {
10            if (nums[i] < pivot) {
11                ans[left++] = nums[i];
12            }
13            if (nums[j] > pivot) {
14                ans[right--] = nums[j];
15            }
16        }
17        
18        while (left <= right) {
19            ans[left++] = pivot;
20        }
21        
22        return ans;
23    }
24};