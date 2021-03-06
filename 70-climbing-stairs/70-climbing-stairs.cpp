class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3) return n;
        vector<int>v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        for(int i = 4; i <= n; i++) {
            int a = v[i-1]+v[i-2];
            v.push_back(a);
        }
        return v[n];
    }
};