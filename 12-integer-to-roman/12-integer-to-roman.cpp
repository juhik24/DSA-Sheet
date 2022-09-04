class Solution {
public:
    // Time = O(number of characters in the resulting string),  Space = O(1) 
    
    string intToRoman(int num) {
        int arr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for(int i = 0; i < 13; i++) {
            while(num >= arr[i]) {
                ans += symbol[i];
                num -= arr[i];
            }
        }
        return ans;
    }
};