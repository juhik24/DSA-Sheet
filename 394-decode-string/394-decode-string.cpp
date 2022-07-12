class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<int>num;
        stack<string>str;
        string ans = "";
        int number = 0;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                number = (number*10) + ch - '0';
            }
            else if(ch == '[') {
                str.push(ans);
                ans = "";
                num.push(number);
                number = 0;
            }
            else if(ch == ']') {
                string temp = ans;
                ans = str.top();
                str.pop();
                int cnt = num.top();
                num.pop();
                while(cnt--) {
                    ans += temp;
                }
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};