class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; i++) {
            int j = abs(nums[i]);
            if(nums[j-1] < 0) {
                ans.push_back(abs(nums[i]));
            }
            nums[j-1] = nums[j-1]*-1;
        }
        return ans;
    }
};