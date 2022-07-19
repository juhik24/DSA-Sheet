class Solution {
public:
    int mx = -1;
    void bfs(int node, vector<int>&vis, vector<int>adj[], int time, vector<int>&informTime) {
        if(adj[node].size() == 0) return;
        vis[node] = 1;
        time=time+informTime[node];
        mx = max(mx, time);
        for(auto i : adj[node]) {
            if(vis[i] == 0) {
                bfs(i, vis, adj, time, informTime);
            }
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        vector<int>adj[n];
        for(int i = 0; i < n; i++) {
            int u = i;
            int v = manager[i];
            if(i == headID) continue;
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        vis[headID] = 1;
        int time = 0;
        bfs(headID, vis, adj, time, informTime);
        return mx;
    }
};