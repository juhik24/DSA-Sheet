class Solution {
public:
    // Time = O(log26n), Space = O(1) 
    
    string convertToTitle(int columnNumber) {
        string ans = "";
        char temp;
        while(columnNumber) {
            columnNumber--;
            temp = 'A' + columnNumber%26;
            ans = temp + ans;
            columnNumber = columnNumber/26;
        }
        return ans;
    }
};