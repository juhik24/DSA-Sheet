class Solution {
public:
    bool dfs(int node, unordered_map<int, bool>&mp, vector<vector<int>>&graph) {
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }
        mp[node] = false;
        for(auto i : graph[node]) {
            if(!dfs(i, mp, graph)) return mp[node];
        }
        mp[node] = true;
        return mp[node];
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n = graph.size();
        unordered_map<int, bool>mp;
        for(int i = 0; i < n; i++) {
            if(dfs(i, mp, graph)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};