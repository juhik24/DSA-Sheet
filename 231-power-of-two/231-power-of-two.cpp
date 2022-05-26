class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1 || n == 2) return true;
        if(n%2 == 0) {
            while(n >= 4) {
                n = n/2;
                if(n%2 != 0) return false;
                else if(n == 4) return true;
            }
            if(n == 4 || n==2) return true;
            else return false;
        }
        else return false;
    }
};