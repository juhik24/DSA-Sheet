class Solution {
public:
    int parent[20005];
    int rank[20005];
    
    void makeSet() {
        for(int i=1; i <= 20004; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void unionSet(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if(rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if(rank[b] < rank[a]) {
            parent[b] = a; 
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        makeSet();
        for(auto i : stones) {
            unionSet(i[0], i[1]+10001);
        }
        unordered_set<int>s;
        for(auto i : stones) {
            int a = i[0];
            s.insert(findPar(a));
        }
        int cnt = s.size();
        return stones.size()-cnt;
    }
};