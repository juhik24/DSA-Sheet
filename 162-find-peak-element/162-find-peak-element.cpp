class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        if(n == 1) return 0;
        int idx;
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > mx) {
                mx = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};