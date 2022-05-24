class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.length();
        int m = b.length();
        int i = n-1, j = m-1;
        char extra='0';
        while(i >= 0 && j >= 0) {
            if(a[i] == '0' && b[j] == '0') {
                if(extra == '1') {
                    ans += '1';
                    extra = '0';
                }
                else ans += '0';
            }
            else if(a[i] == '1' && b[j] == '0') {
                if(extra == '1') ans += '0';
                else ans += '1';
            }
            else if(a[i] == '0' && b[j] == '1') {
                if(extra == '1') ans += '0';
                else ans += '1';
            }
            else if(a[i] == '1' && b[j] == '1') {
                if(extra == '1') {
                    ans += '1';
                }
                else {
                    ans += '0';
                    extra = '1';
                }
            }
            i--;
            j--;
        }
        while(i >= 0) {
            if(a[i] == '0') {
                if(extra == '1') {
                    ans += '1';
                    extra = '0';
                }
                else {
                    ans += '0';
                }
            }
            else if(a[i] == '1') {
                if(extra == '1') {
                    ans += '0';
                }
                else {
                    ans += '1';
                }
            }
            i--;
        }
        while(j >= 0) {
            if(b[j] == '0') {
                if(extra == '1') {
                    ans += '1';
                    extra = '0';
                }
                else {
                    ans += '0';
                }
            }
            else if(b[j] == '1') {
                if(extra == '1') {
                    ans += '0';
                }
                else {
                    ans += '1';
                }
            }
            j--;
        }
        if(extra == '1') {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};