class Solution {
public:
    void solve(int i, int j, int n, vector<vector<int>>&grid, queue<pair<int, int>>&q) {
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        if(grid[i][j] == 0) {
            q.push({i, j});
            grid[i][j] = 1;
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int cnt = 0;
        q.push({-1, -1});
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == -1 && j == -1) {
                if(q.size() > 0) {
                    cnt++;
                    q.push({-1, -1});
                }
            }
            else {
                solve(i-1, j, n, grid, q);
                solve(i+1, j, n, grid, q);
                solve(i, j-1, n, grid, q);
                solve(i, j+1, n, grid, q);
            }
        }
        if(cnt == 0) return -1;
        else return cnt;
    }
};