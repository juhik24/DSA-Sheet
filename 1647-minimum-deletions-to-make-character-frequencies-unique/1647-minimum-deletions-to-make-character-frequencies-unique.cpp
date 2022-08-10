class Solution {
public:
    int minDeletions(string str) {
        int n = str.length();
        unordered_map<char, int>mp;
        unordered_set<int>s;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            mp[str[i]]++;
        }
        for(auto i : mp) {
            int t = i.second;
            while(s.find(t) != s.end()) {
                t--;
                cnt++;
            }
            if(t != 0) s.insert(t);
        }
        return cnt;
    }
};