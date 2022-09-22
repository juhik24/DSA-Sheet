class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') ans += ' ';
            else {
                string temp = "";
                while(s[i] != ' ' && i < n) {
                    temp += s[i];
                    i++;
                }
                i--;
                reverse(temp.begin(), temp.end());
                ans += temp;
            }
            
        }
        return ans;
    }
};