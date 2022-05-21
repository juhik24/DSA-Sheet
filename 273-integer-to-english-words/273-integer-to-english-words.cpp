class Solution {
public:
    string ones[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string tens[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string solve(int n, string s) {
        string ans = "";
        if(n > 19) {
            ans += tens[n/10];
            ans += ones[n%10];
        }
        else ans += ones[n];
        if(n) {
            ans += s;
        }
        return ans;
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string res = "";
        if(num >= 1000000000) {
            res += solve(num/1000000000, "Billion ");
            num = num%1000000000;
        }
        if(num >= 100000000) {
            res += solve((num/100000000), "Hundred ");
            string a = to_string(num);
            num = num%100000000;
            if(num == 0 || (a[1] == '0' && a[2] == '0')) res += "Million ";
        }
        if(num >= 1000000) {
            res += solve((num/1000000), "Million ");
            num = num%1000000;
        }
        if(num >= 100000) {
            res += solve((num/100000), "Hundred ");
            string a = to_string(num);
            num = num%100000;
            if(num == 0 || (a[1] == '0' && a[2] == '0')) res += "Thousand ";
        }
        if(num >= 1000) {
            res += solve((num/1000), "Thousand ");
            num = num%1000;
        }
        if(num >= 100) {
            res += solve((num/100), "Hundred ");
            num = num%100;
        }
        res += solve(num, "");
        int l = res.length();
        if(res[l-1] == ' ') res.pop_back();
        return res;
    }
};