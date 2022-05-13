class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        for(int i = 0; i < n; i++) {
            if(reachable < i) return false;
            if(i+nums[i] > reachable) {
                reachable = i+nums[i];
            }
        }
        return true;
    }
};