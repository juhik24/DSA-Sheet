class Solution {
public:
    int kthFactor(int n, int k) {
        int factor;
        for(int i = 1; i <= n; i++) {
            if(n%i == 0) {
                k--;
            }
            if(k == 0) {
                factor = i;
                break;
            }
        }
        if(factor > n) return -1;
        return factor;
    }
};