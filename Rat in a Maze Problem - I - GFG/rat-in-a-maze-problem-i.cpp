// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, -1, 1, 0};
    vector<string>ans;
    
    void solve(int i, int j, vector<vector<int>>&m, vector<vector<int>>&vis, string move, int n) {
        if(i==n-1 && j == n-1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int idx = 0; idx < 4; idx++) {
            int idx_i = i+di[idx];
            int idx_j = j+dj[idx];
            if(idx_i >= 0 && idx_i < n && idx_j >= 0 && idx_j < n && vis[idx_i][idx_j] == 0 && m[idx_i][idx_j] == 1) {
                vis[i][j] = 1;
                solve(idx_i, idx_j, m, vis, move+dir[idx], n);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n, vector<int>(n, 0));
        string str = "";
        if(m[0][0] == 1) {
            solve(0, 0, m, vis, str, n);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends