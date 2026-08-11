class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int sum=nums[0];
        for(int j=1;j<n;j++){
            if(nums[j-1]+1==nums[j]){
                sum+=nums[j];
            }
            else{
                break;
            }
        }
        while(st.count(sum))
         sum++;
         return sum;
    }
};