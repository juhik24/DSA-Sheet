class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        long long val = (n & (n-1));
        if(val == 0) return true;
        else return false;
    }
};

// Brute force = O(log n base 2), Space = O(1) 

// bool isPowerOfTwo(int n) {
//         if(n == 0) return false;
//         if(n == 1 || n == 2) return true;
//         if(n%2 == 0) {
//             while(n % 2 == 0) {
//                 n = n/2;
//             }
//             if(n == 1) return true;
//             else return false;
//         }
//         else return false;
//     }