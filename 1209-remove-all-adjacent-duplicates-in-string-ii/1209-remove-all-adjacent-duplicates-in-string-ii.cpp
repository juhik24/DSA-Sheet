class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char, int>>st;
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(st.size() == 0 || st.top().first != s[i]) {
                st.push({s[i], 1});
            }
            else if(st.size() > 0 && st.top().second < k && st.top().first == s[i]) {
                st.top().second++;
                if(st.top().second == k) st.pop();
            }
        }
        while(st.size() > 0) {
            for(int i = 0; i < st.top().second; i++) {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};