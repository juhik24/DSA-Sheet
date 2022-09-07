class Solution {
public:
    // Time = O(n^2), Space = O(1) 
    // In this we'll transpose the matrix and then reverse each row
    // In transpose columns will become rows
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //Reverse
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Brute force = Time = O(n^2), Space = O(n^2) 

// void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans[n][n];
//         memset(ans, 0, sizeof(ans));
//         int col = n-1;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 ans[j][col] = matrix[i][j];
//             }
//             col--;
//         }
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 matrix[i][j] = ans[i][j];
//             }
//         }
//     }