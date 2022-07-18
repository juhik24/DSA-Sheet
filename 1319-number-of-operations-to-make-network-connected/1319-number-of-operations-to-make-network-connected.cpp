class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int>adj[]) {
        vis[node] = 1;
        for(auto i : adj[node]) {
            if(vis[i] == 0) {
                dfs(i, vis, adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        int m = connections.size();
        for(int i = 0; i < m; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                components++;
                dfs(i, vis, adj);
            }
        }
        if(m < n-1) return -1;
        int redundant = m - ((n-1) - (components-1));
        if(redundant >= components-1) return components-1;
        else return -1;
    }
};