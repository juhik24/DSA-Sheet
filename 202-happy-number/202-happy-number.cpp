class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n != 1) {
            if(s.find(n) == s.end()) {
                s.insert(n);
            }
            else return false;
            int sum = 0;
            while(n) {
                int a = n%10;
                sum += a*a;
                n = n/10;
            }
            n = sum;
        }
        return true;
    }
};