class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string>st;
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(path[i] == '/') continue;
            string temp = "";
            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            else if(temp == "..") {
                if(st.size() > 0) st.pop();
            }
            else st.push(temp);
        }
        while(st.size() > 0) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.length() == 0) ans += '/';
        return ans;
    }
};