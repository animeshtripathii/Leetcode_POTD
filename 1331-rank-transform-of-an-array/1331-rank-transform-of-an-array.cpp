class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> a = arr;
        sort(a.begin(), a.end());
        
        unordered_map<int, int> mp;
        int rank = 1; 
        for(int i = 0; i < n; i++) {
            if(mp.find(a[i]) == mp.end()) {
                mp[a[i]] = rank;
                rank++; 
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
    }
};