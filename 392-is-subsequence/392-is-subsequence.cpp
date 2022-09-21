class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int j = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int k = j; k < m; k++) {
                if(s[i] == t[k]) {
                    cnt++;
                    flag = true;
                    j = k+1;
                    break;
                }
            }
            if(flag == false) break;
        }
        cout << cnt;
        if(cnt == n) return true;
        return false;
    }
};