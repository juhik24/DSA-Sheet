class Solution {
public:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    
    int dfs(int i, int j, vector<vector<int>>&grid, int gridId) {
        int n = grid.size();
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = gridId;
        int size = 0;
        for(int k = 0; k < 4; k++) {
            int row = i+di[k];
            int col = j+dj[k];
            size += dfs(row, col, grid, gridId);
        }
        return size+1;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int>mp;
        mp[0] = 0;
        int n = grid.size();
        int gridId = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int size = dfs(i, j, grid, gridId);
                    mp[gridId] = size;
                    gridId++;
                }
            }
        }
        int ans = 0, totalSize;
        if(mp.size() > 1) ans = mp[2];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int>s;
                    for(int k = 0; k < 4; k++) {
                        int row = i+di[k];
                        int col = j+dj[k];
                        if(row >= 0 && row < n && col >= 0 && col < n) {
                            s.insert(grid[row][col]);
                        }
                    }
                    totalSize = 1;
                    for(auto id : s) {
                        totalSize += mp[id];
                    }
                    ans = max(ans, totalSize);
                }
            }
        }
        return ans;
    }
};