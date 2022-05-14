class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int majority=0;
        int ele;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            if(i->second > majority) {
                majority = i->second;
                ele = i->first;
            }
        }
        return ele;
    }
};