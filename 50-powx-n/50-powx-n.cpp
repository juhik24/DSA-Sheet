class Solution {
public:
    // Time = O(log n) , Space = O(1) 
    
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1 * nn;
        while(nn) {
            if(nn%2 == 0) {
                x = x*x;
                nn = nn/2;
            }
            else {
                ans = ans * x;
                nn = nn - 1;
            }
        }
        if(n < 0) {
            ans = 1/ans;
        }
        return ans;
    }
};


// Brute force = time = O(n),  space = O(1) 

// double myPow(double x, int n) {
//         double ans = x;
//         if(n == 0) return 1.00000;
//         if(n > 0) {
//             n=n-1;
//             while(n--) {
//                 ans *= x;
//             }
//         }
//         else {
//             n = n+1;
//             while(n < 0) {
//                 ans *= x;
//                 n++;
//             }
//             ans = 1/ans;
//         }
//         return ans;
//     }