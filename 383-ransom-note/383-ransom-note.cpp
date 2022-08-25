class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        int n = magazine.length();
        for(int i = 0; i < n; i++) {
            mp[magazine[i]]++;
        }
        int m = ransomNote.length();
        for(int i = 0; i < m; i++) {
            if(mp.find(ransomNote[i]) == mp.end() || mp[ransomNote[i]] == 0) return false;
            mp[ransomNote[i]]--;
        }
        return true;
    }
};