class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        //vector<int>v;
        int j = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                nums[j] = nums[i];
                j++;
            }
            mp[nums[i]]++;
        }
        nums.resize(j);
        return nums;
    }
};