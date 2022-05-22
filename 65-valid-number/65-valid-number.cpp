class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        bool digit = false, dot = false, eseen = false;
        int cntSign = 0;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(isdigit(ch)) digit = true;
            else if(ch == '+' || ch == '-') {
                if(cntSign == 2) return false;
                if(i > 0 && s[i-1] != 'e') return false;
                if(i == n-1) return false;
                cntSign++;
            }
            else if(ch == '.') {
                if(eseen == true || dot == true) return false;
                if(i == n-1 && digit == false) return false;
                dot = true;
            }
            else if(ch == 'e' || ch == 'E') {
                if(eseen == true || digit == false || i == n-1) return false;
                eseen = true;
            }
            else return false;
        }
        return true;
    }
};