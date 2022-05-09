class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = abs(nums[i]);
            if(nums[j-1] < 0) {
                v.push_back(abs(nums[i]));
            }
            nums[j-1] *= -1;
        }
        return v;
    }
};