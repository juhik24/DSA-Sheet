class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m == 0) return 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(haystack[i] == needle[j]) {
                for(j = 1; j < m; j++) {
                    if(haystack[i+j] != needle[j]) break;
                }
                if(j == m) return i;
                j=0;
            }
        }
        return -1;
    }
};