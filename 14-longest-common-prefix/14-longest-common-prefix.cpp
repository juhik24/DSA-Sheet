class Solution {
public:
    
    // Time = O(n * length of shortes string), space = O(1) 
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int len = INT_MAX;
        string ans = "";
        if(n == 1) return strs[0];
        for(int i = 0; i < n; i++) {
            int j = strs[i].length();
            len = min(len, j);
        }
        for(int i = 0; i < len; i++) {
            int f = 0;
            int j;
            for(j = 1; j < n; j++) {
                if(strs[j-1][i] != strs[j][i]) {
                    f = 1;
                    break;
                }
            }
            if(f == 1) break;
            ans += strs[j-1][i];
        }
        return ans;
    }
};