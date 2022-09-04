class Solution {
public:
    // Time = O(n), Space = O(1) 
    
    int romanToInt(string s) {
        unordered_map<char, int>mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        int n = s.length();
        int ans = mp[s[n-1]];
        for(int i = n-2; i >= 0; i--) {
            if(mp[s[i]] < mp[s[i+1]]) {  // if s[i] is smaller than s[i+1] then subtract the value of s[i] to result
                ans -= mp[s[i]];
            }
            else {
                ans += mp[s[i]];   // if s[i] is greater than s[i+1] then add the value of s[i] to result
            }
        }
        return ans;
    }
};