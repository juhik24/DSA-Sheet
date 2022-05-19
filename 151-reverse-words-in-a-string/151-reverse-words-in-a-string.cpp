class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<string>st;
        for(int i = 0; i < n; i++) {
            string temp = "";
            if(s[i] == ' ') continue;
            while(i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        s.clear();
        while(!st.empty()) {
            if(s == "") s += st.top();
            else s = s + " " + st.top();
            st.pop();
        }
        return s;
    }
};