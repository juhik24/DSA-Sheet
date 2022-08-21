class Solution {
public:
    int solve(vector<int>&nums, int l, int r) {
        if(l == r) return l;
        int mid = (l+r)/2;
        if(nums[mid] > nums[mid+1]) return solve(nums, l, mid);
        return solve(nums, mid+1, r);
    }
    
    int findPeakElement(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};