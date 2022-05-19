class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());
        int i = 0, j = 0, k = 0;
        while(i < n) {
            while(i < n && s[i] != ' ') {
                s[j] = s[i];
                i++; j++;
            }
            if(k < j) {
                reverse(s.begin()+k, s.begin()+j);
                if(j == n) break;
                s[j] = ' ';
                j++;
                k = j;
            }
            i++;
        }
        if(j > 0 && s[j-1] == ' ') j--;
        s.resize(j);
        return s;
    }
};