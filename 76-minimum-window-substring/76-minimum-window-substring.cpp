class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        unordered_map<char, int>mp;
        for(int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        int res = INT_MAX;
        int cnt = mp.size();
        int i = 0, j = 0, start;
        while(j < n) {
            mp[s[j]]--;
            if(mp[s[j]] == 0) cnt--;
            if(cnt == 0) {
                while(cnt == 0) {
                    if(j-i+1 < res) {
                        res = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) cnt++;
                    i++;
                }
            }
            j++;
        }
        if(res != INT_MAX) return s.substr(start, res);
        else return "";
    }
};