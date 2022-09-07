class Solution {
public:
    // Time = O(n), Space = O(n) 
    
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char, int>mp2;
        for(int i = 0; i < t.length(); i++) {
            mp2[t[i]]++;
        }
        int mcnt=0;
        int start = 0;
        int dmcnt = t.length();
        int length = INT_MAX;
        unordered_map<char, int>mp1;
        int i = 0, j = 0;
        while(i < s.length()) {
            mp1[s[i]]++;
            if(mp1[s[i]] <= mp2[s[i]]) {
                mcnt++;
            }
            while(mcnt == dmcnt) {
                if(length > i-j+1) {
                    start = j;
                    length = i-j+1;
                }
                mp1[s[j]]--;
                if(mp1[s[j]] < mp2[s[j]]) {
                    mcnt--;
                }
                j++;
            }
            i++;
        }
        if(length == INT_MAX) return "";
        return s.substr(start, length);
    }
};