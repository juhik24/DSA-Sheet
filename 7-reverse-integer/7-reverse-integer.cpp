class Solution {
public:
    // Time = O(log x), Space = O(1) 
    
    int reverse(int x) {
        int num = 0;
        while(x) {
            int a = x%10;
            x = x/10;
            if(num > INT_MAX/10 || (num == INT_MAX/10 && a > INT_MAX%10)) return 0;
            if(num < INT_MIN/10 || (num == INT_MIN/10 && a < INT_MIN%10)) return 0;
            num = num*10 + a;
        }
        return num;
    }
};