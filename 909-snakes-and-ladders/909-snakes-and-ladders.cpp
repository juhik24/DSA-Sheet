class Solution {
public:
    pair<int, int> coordinates(int x, int n) // find the coordinates given integer
    {
        int r = n - (x-1)/n -1;
        int c = (x-1)%n;
        if(r%2==n%2)
            return {r,n-c-1};
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps = 0;
        queue<int> q;
        q.push(1);
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // so that we are not trapped in a loop
        visited[board.size()-1][0]=true;
        while(q.size()!=0) // work until the queue is empty
        {
            int size = q.size();
            for(int i=0; i<size; i++) // for each step use all the elements in the queue
            {
                int x = q.front();
                if(x == n*n) return steps;
                q.pop();
                for(int j=1; j<=6; j++) // all possible moves
                {
                    if(j+x > n*n) break;
                    pair<int, int> p = coordinates(x+j, n);
                    int r = p.first;
                    int c = p.second;
                    if(visited[r][c]) continue;
                    visited[r][c] = true;
                    if(board[r][c]!=-1) // if snake or ladder
                        q.push(board[r][c]);
                    else
                        q.push(j+x);
                }
            }
            steps++;
        }
        return -1;
    }
};