class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char>str;
        int i = 0, j = 0;
        int len = 0;
        while(i < n && j < n) {
            if(str.find(s[j]) == str.end()) {
                str.insert(s[j]);
                j++;
                len = max(len, j-i);
            }
            else {
                str.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};