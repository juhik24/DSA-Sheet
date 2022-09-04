class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for(int i = 0; i < m; i++) {
            if(mp.find(t[i]) == mp.end()) return false;
            else {
                mp[t[i]]--;
                if(mp[t[i]] == 0) mp.erase(t[i]);
            }
        }
        return true;
    }
};