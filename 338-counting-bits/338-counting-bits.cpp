class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        v[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(i%2 == 0) {
                int a = i/2;
                v[i] = v[a];
            }
            else {
                int a = i/2;
                v[i] = 1+v[a];
            }
        }
        return v;
    }
};