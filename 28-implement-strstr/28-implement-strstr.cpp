class Solution {
public:
    bool explore(string haystack, string needle, int i, int size) {
        int n = haystack.length();
        while(i < n && size < needle.length()) {
            if(haystack[i] != needle[size]) return false;
            else if(haystack[i] == needle[size]) {
                if(size == needle.length()-1) return true;;
                size++;
                i++;
            }
        }
        if(size-1 == needle.length()-1) return true;
        else return false;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(n < m) return -1;
        if(m == 0 || n == 0) return 0;
        bool ans;
        for(int i = 0; i < n; i++) {
            if(haystack[i] == needle[0]) {
                ans = explore(haystack, needle, i, 0);
            }
            if(ans == true) return i;
        }
        return -1;
    }
};