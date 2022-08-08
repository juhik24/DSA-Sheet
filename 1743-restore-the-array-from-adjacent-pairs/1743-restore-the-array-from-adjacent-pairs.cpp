class Solution {
public:
    vector<int>ans;
    
    void dfs(int node, unordered_map<int, vector<int>> &mp, set<int>&s) {
        if(s.find(node) != s.end()) return;
        ans.push_back(node);
        s.insert(node);
        for(auto i : mp[node]) {
            dfs(i, mp, s);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>>mp;
        int src;
        for(auto i : adjacentPairs) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        for(auto i : mp) {
            if(i.second.size() == 1) src = i.first;
        }
        set<int>s;
        dfs(src, mp, s);
        return ans;
    }
};