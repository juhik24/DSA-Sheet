class Solution {
public:
    // Time = O(n^2), Space = O(n^2) 
    
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        //check for substring of length 1
        int maxLen = 1;
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // check for substring of length 2
        int start = 0;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        //check for substring greater than 2
        // k is length of substring
        for(int k = 3; k <= n; k++) {
            //Fix the starting index
            for(int i = 0; i < n-k+1; i++) {
                int j = i+k-1;
                // checking for substring from ith index to jth index
                // if and only if s[i+1] and s[j-1] is palindrome
                if(dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if(k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
        string ans = "";
        int low = start, high = start+maxLen-1;
        for(int i = low; i <= high; i++) {
            ans += s[i];
        }
        return ans;
    }
};


// Brute force

// produce all the possible substrings and check if it is palindrome or not

// To produce substrings it will take O(n^2) time and to check if it is palindrome it will take O(n) time
// so time complexity is O(n^3), Space = O(1) 