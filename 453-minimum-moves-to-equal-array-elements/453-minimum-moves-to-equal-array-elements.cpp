class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
        }
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int ans = sum - (mn*n);
        return ans;
    }
};