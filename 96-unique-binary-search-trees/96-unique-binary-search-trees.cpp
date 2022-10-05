class Solution {
public:
    // Time = O(n^2), Space = O(n)
    
    // Solved using nth catalan number ( 1 1 2 5 14)
    // C0 = 1, C1 = 0
    // C2 = (C0*C1) + (C1 * C0)
    // C3 = (C0*C2) + (C1*C1) + (C2*C0), C4 = (C0*C3) + (C1*C2) + (C2*C1) + (C3*C0)
    // and so on
    
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