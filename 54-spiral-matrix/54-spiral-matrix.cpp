class Solution {
public:
    // Time = O(n*m), Space = O(1) 
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;
        int top = 0, down = n-1, left = 0, right = m-1;
        int dir = 0;
        while(top <= down && left <= right) {
            if(dir == 0) {  // left to right
                for(int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1) {  // top to down
                for(int i = top; i <= down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2) {  // right to left
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(dir == 3) {   // down to top
                for(int i = down; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};