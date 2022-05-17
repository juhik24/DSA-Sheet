class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int n = 13;
        int arr[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ch[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        for(int i = n-1; i >= 0; i--) {
            if(num == arr[i]) {
                ans+= ch[i];
                break;
            }
            if(num/arr[i]>0) {
                int cnt = num/arr[i];
                while(cnt--) {
                    ans += ch[i];
                }
            }
            num = num%arr[i];
        }
        return ans;
    }
};