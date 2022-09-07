class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long num = 0;
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        bool sign = false;
        int cntSign = 0;
        while(s[i] == '+' || s[i] == '-') {
            if(s[i] == '-') {
                sign = true;
                i++;
            }
            else if(s[i] == '+') i++;
            cntSign++;
        }
        while(i < n && isdigit(s[i])) {
            num = num*10+(s[i]-'0');
            if(sign == true && num*-1 <= INT_MIN) return INT_MIN;
            else if(sign == false && num >= INT_MAX) return INT_MAX;
            i++;
        }
        if(cntSign > 1) return 0;
        if(sign) return -num;
        return num;
    }
};