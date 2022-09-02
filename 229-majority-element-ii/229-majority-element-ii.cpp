class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidates;
        int n = nums.size();
        unordered_map<int, int>mp;
        vector<int>ans;
        int cnt = n/3;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for(auto i : mp) {
            if(i.second > cnt) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};