class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroes = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) zeroes++;
        }
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        while(zeroes--) {
            nums[n-1] = 0;
            n--;
        }
    }
};