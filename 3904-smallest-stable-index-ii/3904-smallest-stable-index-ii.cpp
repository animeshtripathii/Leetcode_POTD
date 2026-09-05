class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pMax(n),sMin(n);
        pMax[0]=nums[0];
        for(int i=1;i<n;i++){
            pMax[i]=max(pMax[i-1],nums[i]);
        }
        sMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sMin[i]=min(sMin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(pMax[i]-sMin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};