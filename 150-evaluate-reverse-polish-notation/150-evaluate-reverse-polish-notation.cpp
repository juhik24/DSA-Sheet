class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i = 0; i < n; i++) {
            if(tokens[i] == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int ans = a+b;
                st.push(ans);
            }
            else if(tokens[i] == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int ans = b-a;
                st.push(ans);
            }
            else if(tokens[i] == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int ans = b*a;
                st.push(ans);
            }
            else if(tokens[i] == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int ans = b/a;
                st.push(ans);
            }
            else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};