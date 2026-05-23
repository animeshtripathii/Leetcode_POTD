1class Solution {
2public:
3    bool check(vector<int>& nums) {
4       int n = nums.size();
5       bool rotated = false;
6       for(int i = 0; i < n; i++){
7           if(nums[i] > nums[(i+1)%n]){
8               if(rotated) return false;
9               rotated = true;
10           }
11           else if(nums[i] == nums[(i+1)%n]) continue;
12       }
13       return true;
14    }
15};