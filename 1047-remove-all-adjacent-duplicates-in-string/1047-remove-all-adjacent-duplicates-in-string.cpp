class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(st.size() == 0 || st.top() != s[i]) st.push(s[i]);
            else {
                st.pop();
            }
        }
        string ans = "";
        while(st.size() > 0) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};