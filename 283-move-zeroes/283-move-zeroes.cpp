class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) zero++;
        }
        int j = 0;
        while(j < n) {
            int i;
            for(i = 0; i < n; i++) {
                if(nums[i] != 0) {
                    nums[j] = nums[i];
                    j++;
                }
            }
             break;
        }
        int i = n-1;
        while(zero--) {
            nums[i] = 0;
            i--;
        }
    }
};