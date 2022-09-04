class Solution {
public:
    
    // Time = O(n), Space = O(n) 
    
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if(st.size() > 0 && st.top() == '(' && s[i] == ')') st.pop();
            else if(st.size() > 0 && st.top() == '{' && s[i] == '}') st.pop();
            else if(st.size() > 0 && st.top() == '[' && s[i] == ']') st.pop();
            else return false;
        }
        if(st.size() == 0) return true;
        else return false;
    }
};