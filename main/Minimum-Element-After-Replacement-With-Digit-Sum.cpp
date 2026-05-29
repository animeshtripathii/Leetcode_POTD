1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<n;i++){
6            int c=nums[i];
7            int sum=0;
8            while(c){
9             int k=c%10;
10             sum+=k;
11             c=c/10;
12            }
13            nums[i]=sum;
14        }
15        return *min_element(nums.begin(),nums.end());
16    }
17};