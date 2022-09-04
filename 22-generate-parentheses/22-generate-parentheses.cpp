class Solution {
public:
    //Backtracking method - in this we'll add open parenthesis if open count < n
    // and we'll add a closing parenthesis if open count > closed
    // and we'll stop adding parenthesis when open == close == n
    
    void solve(int open, int close, vector<string>&ans, string &op) {
        if(open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }
        if(open != 0) {
            string op1 = op;
            op1.push_back('(');
            solve(open-1, close, ans, op1);
        }
        if(close > open) {
            string op2 = op;
            op2.push_back(')');
            solve(open, close-1, ans, op2);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = n, close = n;
        string op = "";
        solve(open, close, ans, op);
        return ans;
    }
};