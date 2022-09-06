class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int>st;
        char sign = '+';
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(isdigit(s[i])) {
                int val = 0;
                while(isdigit(s[i])) {
                    val = (val*10)+(s[i]-'0');
                    i++;
                }
                i--;
                if(sign == '+') {
                    st.push(val);
                }
                else if(sign == '-') {
                    st.push(-val);
                }
                else if(sign == '*') {
                    int a = st.top();
                    st.pop();
                    int sum = val*a;
                    st.push(sum);
                }
                else if(sign == '/') {
                    int a = st.top();
                    st.pop();
                    int sum = a/val;
                    st.push(sum);
                }
            }
            else if(s[i] != ' ') {
                sign = s[i];
            }
        }
        int sum = 0;
        while(st.size() > 0) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};