class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        vector<int>v;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        for(auto i = mp.begin(); i != mp.end(); i++) {
            v.push_back(i->second);
        }
        sort(v.begin(), v.end());
        unordered_set<int>st;
        int n = v.size();
        int cnt = 0;
        st.insert(v[n-1]);
        for(int i = n-2; i >= 0; i--) {
            if(st.find(v[i]) != st.end()) {
                while(st.find(v[i]) != st.end() && v[i] > 0) {
                    v[i]--;
                    cnt++;
                }
            }
            st.insert(v[i]);
        }
        return cnt;
    }
};