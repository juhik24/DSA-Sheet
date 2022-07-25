class Solution {
public:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};
    
    int dfs(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>> &mem) {
        if(mem[i][j] > 0) {
            return mem[i][j];
        }
        int cnt = 0;
        for(int k = 0; k < 4; k++) {
            int row = i+di[k];
            int col = j+dj[k];
            if(row >= 0 && row < n && col >= 0 && col < m && matrix[i][j] < matrix[row][col]) {
                cnt = max(cnt, dfs(row, col, matrix, n, m, mem));
            }
        }
        mem[i][j] = cnt+1;
        return cnt+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int len = 0;
        vector<vector<int>> mem(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = dfs(i, j, matrix, n, m, mem);
                len = max(len, cnt);
            }
        }
        return len;
    }
};