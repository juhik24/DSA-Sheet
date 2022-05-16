class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        if(n == 1) return false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ')' && st.size() > 0 && st.top() == '(') {
                st.pop();
            }
            else if(s[i] == '}' && st.size() > 0 && st.top() == '{') {
                st.pop();
            }
            else if(st.size() > 0 && s[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else return false;
        }
        if(st.size() == 0) return true;
        else return false;
    }
};