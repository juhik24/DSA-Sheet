// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    int di[8] = {-1, 1, 1, -1, -2, -2, 2, 2};
    int dj[8] = {2, 2, -2, -2, -1, 1, -1, 1};
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int steps = 0;
	    vector<vector<int>>vis(N+1, vector<int>(N+1, 0));
	    queue<pair<int, int>>q;
	    q.push({KnightPos[0], KnightPos[1]});
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    while(!q.empty()) {
	        int size = q.size();
	        for(int i = 0; i < size; i++) {
	            int m = q.front().first, n = q.front().second;
	            q.pop();
	            if(m == TargetPos[0] && n == TargetPos[1]) return steps;
	            for(int i = 0; i < 8; i++) {
	                int x = m+di[i];
	                int y = n+dj[i];
	                if(x > 0 && x <= N && y > 0 && y <= N && vis[x][y] == 0) {
	                    q.push({x, y});
	                    vis[x][y] = 1;
	                }
	            }
	        }
	        steps++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends