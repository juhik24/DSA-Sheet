class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            total += i;
            sum += nums[i];
        }
        total += n;
        return total - sum;
    }
};