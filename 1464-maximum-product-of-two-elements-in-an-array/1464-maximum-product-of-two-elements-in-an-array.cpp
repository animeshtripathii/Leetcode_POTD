class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi =-1;
        int s_maxi=maxi;

        for(int i = 0; i < n; i++){
            if(nums[i]>=maxi){
                s_maxi=maxi;
                maxi=nums[i];
            }
            else if(nums[i]<=maxi&&nums[i]>s_maxi){
                s_maxi=nums[i];
            }
        }
    int c=maxi-1;
    int d=s_maxi-1;
    return c*d;
    }
};