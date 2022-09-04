class Solution {
public:
    
    // Time = O(nlogn), Space = O(1) 
    
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;
    }
};


// Brute force = Time = O(n), Space = O(n) 

// bool isAnagram(string s, string t) {
//         unordered_map<char, int>mp;
//         int n = s.length();
//         int m = t.length();
//         if(n != m) return false;
//         for(int i = 0; i < n; i++) {
//             mp[s[i]]++;
//         }
//         for(int i = 0; i < m; i++) {
//             if(mp.find(t[i]) == mp.end()) return false;
//             else {
//                 mp[t[i]]--;
//                 if(mp[t[i]] == 0) mp.erase(t[i]);
//             }
//         }
//         return true;
//     }