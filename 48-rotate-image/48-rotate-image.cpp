class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans[n][n];
        memset(ans, 0, sizeof(ans));
        int col = n-1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][col] = matrix[i][j];
            }
            col--;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};