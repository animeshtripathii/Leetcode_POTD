class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);
        int currentGroup = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++;
            }
            group[i] = currentGroup;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            ans.push_back(group[q[0]] == group[q[1]]);
        }
        
        return ans;
    }
};