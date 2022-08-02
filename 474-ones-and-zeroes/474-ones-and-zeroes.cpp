class Solution {
public:
    int dp[101][101];
    
    vector<int> count(string str) {
        int n = str.length();
        int m = 0, k = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '0') m++;
            else k++;
        }
        return {m, k};
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i = 0; i < strs.size(); i++) {
            vector<int>cnt = count(strs[i]);
            for(int j = m; j >= cnt[0]; j--) {
                for(int k = n; k >= cnt[1]; k--) {
                    dp[j][k] = max(dp[j-cnt[0]][k-cnt[1]]+1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};