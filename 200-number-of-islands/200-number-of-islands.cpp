class Solution {
public:
    void solve(vector<vector<char>>&grid, int i, int j, int col, int row) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1') return;
        grid[i][j] = '2';
        solve(grid, i+1, j, col, row);
        solve(grid, i-1, j, col, row);
        solve(grid, i, j+1, col, row);
        solve(grid, i, j-1, col, row);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    solve(grid, i, j, m, n);
                }
            }
        }
        return cnt;
    }
};