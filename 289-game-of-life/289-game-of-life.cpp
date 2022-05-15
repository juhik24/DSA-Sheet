class Solution {
public:
    int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    int explore(vector<vector<int>>&board, int i, int j, int n, int m) {
        int cnt=0;
        for(int k = 0; k < 8; k++) {
            if(i+di[k] < 0 || i+di[k] >= n || j+dj[k] < 0 || j+dj[k] >= m) continue;
            else if(board[i+di[k]][j+dj[k]] == 1 || board[i+di[k]][j+dj[k]] == 3) cnt++;
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt;
                cnt = explore(board, i, j, n, m);
                if((cnt < 2 || cnt > 3) && board[i][j] == 1) {
                    board[i][j] = 1;
                }
                else if((cnt == 2 || cnt == 3) && board[i][j] == 1) {
                    board[i][j] = 3;
                }
                else if(cnt == 3 && board[i][j] == 0) {
                    board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};