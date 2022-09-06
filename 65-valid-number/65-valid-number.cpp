class Solution {
public:
    // Time = O(n), Space = O(1)
    
    // Conditions for invalid number:
    // digits(flag) -> if any number doesn't have any digit then it is invalid. so we need a flag for that.
    // minus/plus -> if sign comes at the end of the string then it is invalid.
                 // if sign comes in between but the character before that is not e then also it is invalid.
              // if there are more than 2 minus/plus then also it is invalid number.
    // dot -> if dot comes at the end of the string and no digits is present then it is invalid
             // if two dots are present in the string then also it is invalid.
             // and if there is just a dot present in the string then also it is invalid.
    // e/E -> if e present more than once then it is invalid.
            // if the string start or end with a e/E then also it is invalid.
    
    bool isNumber(string s) {
        int n = s.length();
        bool digit = false, dot = false, eseen = false;
        int cntSign = 0;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(isdigit(ch)) digit = true;
            else if(ch == '+' || ch == '-') {
                if(i == n-1) return false;
                else if(cntSign == 2) return false;
                else if(i > 0 && s[i-1] != 'e') return false;
                cntSign++;
            }
            else if(ch == '.') {
                if(i == n-1 && digit == false) return false;
                else if(dot == true || eseen == true) return false;
                dot = true;
            }
            else if(ch == 'e' || ch == 'E') {
                if(eseen == true || digit == false) return false;
                if(i == 0 || i == n-1) return false;
                eseen = true;
            }
            else return false;
        }
        return true;
    }
};