class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char>st;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')' && i != n-1) {
                if(s[i+1] == ')') {
                    if(st.size() > 0) st.pop();
                    else {
                        cnt++;
                    }
                    i++;
                }
                else {
                    if(st.size() > 0) {
                        st.pop();
                        cnt += 1;
                    }
                    else {
                        cnt += 2;
                    }
                }
            }
            else if(s[i] == ')' && i == n-1) {
                if(st.size() > 0) {
                    st.pop();
                    cnt++;
                }
                else cnt+=2;
            }
        }
        while(st.size() > 0) {
            st.pop();
            cnt += 2;
        }
        return cnt;
    }
};