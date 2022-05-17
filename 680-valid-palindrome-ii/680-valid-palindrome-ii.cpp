class Solution {
public:
    int f = 0;
    bool check(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        if(n == 1) return true;
        int i = 0, j = n-1, f = 0;
        while(i < j) {
            if(s[i] != s[j]) {
                return (check(s, i+1, j) || check(s, i, j-1));
            }
            i++;
            j--;
        
        }
        return true;
    }
};