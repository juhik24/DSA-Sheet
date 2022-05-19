// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length();
        int m = p.length();
        unordered_map<char, int>mp;
        for(int i = 0; i < m; i++) {
            mp[p[i]]++;
        }
        int cnt = mp.size();
        int res = INT_MAX;
        int i=0, j=0, start;
        while(j < n) {
            mp[s[j]]--;
            if(mp.find(s[j]) != mp.end()) {
                if(mp[s[j]] == 0) cnt--;
            }
            //if(mp[s[j]] == 0) count--;
            if(cnt == 0) {
                while(cnt==0) {
                    if(j-i+1 < res) {
                        res = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) cnt++;
                    i++;
                }
            }
            j++;
        }
        if(res != INT_MAX) return s.substr(start, res);
        else return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends