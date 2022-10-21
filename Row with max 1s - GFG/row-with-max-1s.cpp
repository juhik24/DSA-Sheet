//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
   int binarySearch(vector<vector<int>>&arr, int row) {
        int low = 0, high = arr[row].size()-1;
        int idx = -1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[row][mid] == 1) {
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //cout << idx << " ";
        return idx;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int row=-1;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            int idx = binarySearch(arr, i);
            int cnt=INT_MIN;
            if(idx != -1) {
                cnt = arr[i].size() - idx;
            }
            if(cnt > mx) {
                mx = cnt;
                row = i;
            }
        }
        return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends