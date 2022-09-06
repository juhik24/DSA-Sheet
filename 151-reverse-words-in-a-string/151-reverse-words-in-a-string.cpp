class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        stack<string>st;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            string temp = "";
            while(i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        while(st.size() > 0) {
            if(ans == "") {
                ans += st.top();
            }
            else {
                ans += " " + st.top();
            }
            st.pop();
        }
        return ans;
    }
};