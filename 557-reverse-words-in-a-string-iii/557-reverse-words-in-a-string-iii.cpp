class Solution {
public:
    // Time = O(n), Space = O(1);
    
    string reverseWords(string s) {
        int n = s.length();
        int j = 0, i;
        for(i = 0; i < n; i++) {
            if(s[i] == ' ') {
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
        reverse(s.begin()+j, s.begin()+i);
        return s;
    }
};