class Solution {
public:
    // Time = O(max length of(a, b)), Space = O(1) 
    
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int carry = 0;
        string ans = "";
        int i = n-1, j = m-1;
        while(i >= 0 || j >= 0 || carry != 0) {
            int x = 0, y = 0;
            if(i >= 0 && a[i] == '1') x = 1;
            if(j >= 0 && b[j] == '1') y = 1;
            int sum = (x+y+carry) % 2;
            ans = to_string(sum) + ans;
            carry = (x+y+carry)/2;
            if(i >= 0) i--;
            if(j >= 0) j--;
        }
        return ans;
    }
};