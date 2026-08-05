class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& isSuspicious) {
        isSuspicious[node] = true;
        for (int neighbor : adj[node]) {
            if (!isSuspicious[neighbor]) {
                dfs(neighbor, adj, isSuspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> isSuspicious(n, false);
        dfs(k, adj, isSuspicious);

        bool canRemove = true;
        for (auto& edge : invocations) {
            int caller = edge[0]; 
            int callee = edge[1]; 
            
            if (!isSuspicious[caller] && isSuspicious[callee]) {
                canRemove = false;
                break;
            }
        }

        vector<int> ans;
        if (canRemove) {
            for (int i = 0; i < n; i++) {
                if (!isSuspicious[i]) {
                    ans.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};