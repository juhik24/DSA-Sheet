// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>s;
        int ans;
        for(int i = 0; i < S.length(); i++) {
            char c = S[i];
            if(c <= '9' && c >= '0') {
                s.push(c - '0');
            }
            else {
                int a, b;
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                if(S[i] == '+') {
                    ans = b+a;
                    s.push(ans);
                }
                else if(S[i] == '-') {
                    ans = b-a;
                    s.push(ans);
                }
                else if(S[i] == '*') {
                    ans = b*a;
                    s.push(ans);
                }
                else if(S[i] == '/') {
                    ans = b/a;
                    s.push(ans);
                }
            }
        }
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends