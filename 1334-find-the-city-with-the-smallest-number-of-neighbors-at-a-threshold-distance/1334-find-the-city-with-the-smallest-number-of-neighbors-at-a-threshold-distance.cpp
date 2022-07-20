class Solution {
public:
    void dijkstra(int src, vector<pair<int, int>> &ans, vector<pair<int, int>> adj[], int distanceThreshold, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i : adj[node]) {
                int next = i.first;
                int wt = i.second;
                if(dist[node]+wt < dist[next]) {
                    dist[next] = dist[node]+wt;
                    pq.push({dist[next], next});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dist[i] <= distanceThreshold && i != src) {
                cnt++;
            }
        }
        ans.push_back({cnt, src});
    }
    
    bool static cmp(const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.first != p2.first) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>>adj[n];
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<pair<int, int>>ans;
        for(int i = 0; i < n; i++) {
            dijkstra(i, ans, adj, distanceThreshold, n);
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans[0].second;
    }
};