class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = solve(m, n, i+1, j, dp) + solve(m , n, i, j+1, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, dp);
    }
};

// Time = O(2^max(m, n))->exponential time, Space = O(2^max(m, n))->recursion stack
    
//     void solve(int m, int n, int i, int j, int &paths) {
//         if(i < m && j < n && i >= 0 && j >= 0) {
//             if(i == m-1 && j == n-1) paths++;
//             solve(m, n, i+1, j, paths);
//             solve(m, n, i, j+1, paths);
//         }
//     }
     
//     int uniquePaths(int m, int n) {
//         int paths = 0;
//         solve(m, n, 0, 0, paths);
//         return paths;
//     }