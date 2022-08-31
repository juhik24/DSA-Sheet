class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    bool explore(vector<vector<char>>& board, int i, int j, int size, string &word) {
        if(size == word.length()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || word[size] != board[i][j]) return false;
        char ch = board[i][j];
        board[i][j] = '@';
        for(int k = 0; k < 4; k++) {
            bool ans = explore(board, i+di[k], j+dj[k], size+1, word);
            if(ans) {
                board[i][j] = ch;
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    bool ans = explore(board, i, j, 0, word);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};