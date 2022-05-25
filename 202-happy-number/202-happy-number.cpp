class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>mp;
        while(n != 1) {
            if(mp.find(n) == mp.end()) mp[n]++;
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