class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(int node, int parent, vector<int>&vis, vector<int>&tin, vector<int>&low, int &timer, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto i : adj[node]) {
            if(i == parent) continue;
            if(vis[i] == 0) {
                dfs(i, node, vis, tin, low, timer, adj);
                low[node] = min(low[node], low[i]);
                if(low[i] > tin[node]) {
                    ans.push_back({node, i});
                }
            }
            else {
                low[node] = min(low[node], tin[i]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>tin(n, -1);
        vector<int>vis(n, 0);
        vector<int>low(n, -1);
        vector<int>adj[n];
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, -1, vis, tin, low, timer, adj);
            }
        }
        return ans;
    }
};