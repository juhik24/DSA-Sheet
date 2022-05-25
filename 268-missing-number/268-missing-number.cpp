class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX ;
        for(int i = 0; i < n; i++) {
            if(i != nums[i]) {
                ans = i;
                break;
            }
        }
        if(ans == INT_MAX) return n;
        else return ans;
    }
};