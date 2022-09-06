class Solution {
public:
    // Time = O(n*klogk) - k is length of string, Space = O(n) 
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};