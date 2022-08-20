class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int ones = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') ones++;
        }
        int ans = 0, i = 0;
        while(ones) {
            if(s[i] == '1') {
                ones--;
                i++;
            }
            else {
                for(int j = i; j < n-1; j++) {
                    if(s[j] == '0' && s[j+1] == '1') {
                        s[j] = '1';
                        s[j+1] = '0';
                        j++;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};