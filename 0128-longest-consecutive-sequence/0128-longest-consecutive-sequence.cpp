class Solution {
public:
    // Time = O(nlogn), Space = O(1) 
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        int ele = nums[0];
        for(int i = 1; i < n; i++) {
            if(ele+1 == nums[i]) {
                ele = ele+1;
                len++;
            }
            else if(ele+1 < nums[i]) {
                ele = nums[i];
                len = 1;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};