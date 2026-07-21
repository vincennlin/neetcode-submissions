class Solution {
    int count = 0;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        count = 0;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (int nei : adj[node]) {
            dfs(adj, visited, nei);
        }
    }
};