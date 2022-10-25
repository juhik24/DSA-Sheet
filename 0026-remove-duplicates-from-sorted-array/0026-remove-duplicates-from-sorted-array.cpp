class Solution {
public:
    // Time = O(n), Space = O(1) 
    
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int j = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
                count++;
            }
        }
        return count;
    }
};