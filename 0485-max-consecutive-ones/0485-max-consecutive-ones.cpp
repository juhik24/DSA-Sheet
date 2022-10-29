class Solution {
public:
    // Time = O(n), Space = O(1) 
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max_ones = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                max_ones = max(max_ones, cnt);
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        max_ones = max(max_ones, cnt);
        return max_ones;
    }
};