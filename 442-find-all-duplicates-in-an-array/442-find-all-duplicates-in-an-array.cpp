class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<int>v;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                v.push_back(nums[i]);
            }
            mp[nums[i]]++;
        }
        return v;
    }
};