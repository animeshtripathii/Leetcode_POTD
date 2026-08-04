class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>arr;
        int c=*max_element(begin(nums),end(nums));
        int z=*min_element(begin(nums),end(nums));
        set<int>mp;
        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        for(int i=z;i<=c;i++){
         if(mp.find(i)==mp.end())
             arr.push_back(i);
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};