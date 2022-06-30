class Solution {
public:
    int parent[1002];
    
    int find(int a) {
        while(parent[a] != a) {
            a = parent[a];
        }
        return a;
    }
    
    void union_edges(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);
        if(aRoot != bRoot) {
            parent[bRoot] = aRoot;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++) {
            if(find(edges[i][0]) == find(edges[i][1])) {
                return {edges[i][0], edges[i][1]};
            }
            union_edges(edges[i][0], edges[i][1]);
        }
        return {0, 0};
    }
};