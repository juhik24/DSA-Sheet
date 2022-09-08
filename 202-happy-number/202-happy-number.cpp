class Solution {
public:
    // Time = O(nlogn), Space = O(1) 
    
    bool isHappy(int n) {
        if(n == 1 || n == 7) return true;
        int sum = n, x = n;
        // This loop executes till the sum of square of digits
        // obtained is not a single digit number
        while(sum > 9) {
            sum = 0;
            while(x) {
                int a = x%10;
                sum += a*a;
                x = x/10;
            }
            if(sum == 1 || sum == 7) return true;
            x = sum;
        }
        return false;
    }
};

// Time = O(nlogn), Space = O(n) 

// bool isHappy(int n) {
//         unordered_set<int>s;
//         while(n != 1) {
//             if(s.find(n) == s.end()) {
//                 s.insert(n);
//             }
//             else return false;
//             int sum = 0;
//             while(n) {
//                 int a = n%10;
//                 sum += a*a;
//                 n = n/10;
//             }
//             n = sum;
//         }
//         return true;
//     }