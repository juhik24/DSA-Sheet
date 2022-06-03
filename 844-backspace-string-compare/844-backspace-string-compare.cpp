class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        string str1 = "", str2 = "";
        int i = 0, j = 0;
        stack<char>st1, st2;
        while(i < n1 || j < n2) {
            if(i < n1) {
                char ch = s[i];
                if(ch != '#') st1.push(ch);
                else {
                    if(st1.size() > 0) {
                        st1.pop();
                    }
                }
                i++;
            }
            if(j < n2) {
                char ch = t[j];
                if(ch != '#') st2.push(ch);
                else {
                    if(st2.size() > 0) {
                        st2.pop();
                    }
                }
                j++;
            }
        }
        while(st1.size() > 0) {
            char ch = st1.top();
            str1 += ch;
            st1.pop();
        }
        while(st2.size() > 0) {
            char ch = st2.top();
            str2 += ch;
            st2.pop();
        }
        if(str1 == str2) return true;
        else return false;
    }
};