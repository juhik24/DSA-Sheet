class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int>st;
        char sign = '+';
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                int val = 0;
                while(i < n && isdigit(s[i])) {
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(sign == '+') st.push(val);
                else if(sign == '-') st.push(-val);
                else if(sign == '*') {
                    int a = st.top();
                    st.pop();
                    int ans = a*val;
                    st.push(ans);
                }
                else if(sign == '/') {
                    int a = st.top();
                    st.pop();
                    int ans = a/val;
                    st.push(ans);
                }
            }
            else if(s[i] != ' ') sign = s[i]; 
        }
        int sum = 0;
        while(st.size() > 0) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};