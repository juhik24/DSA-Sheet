class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int l = 0, r = i-1;
            int sum = 0;
            while(l < i) {
                sum = sum + (dp[l]*dp[r]);
                l++;
                r--;
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};