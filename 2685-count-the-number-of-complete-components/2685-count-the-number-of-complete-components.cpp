class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);

        if (adj.find(u) != adj.end()) {
            for (auto &v : adj[u]) {
                if (!visited[v]) {
                    dfs(v, adj, visited, component);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                int vertices = component.size();
                int edgeCount = 0;

                for (auto node : component) {
                    edgeCount += adj[node].size();
                }

                edgeCount /= 2;

                if (edgeCount == vertices * (vertices - 1) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};