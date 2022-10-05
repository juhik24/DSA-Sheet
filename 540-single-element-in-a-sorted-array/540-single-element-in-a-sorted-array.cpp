class Solution {
public:
    // Time = O(log n), Space = O(1) 
    
    // Binary Search
    // in order to check for left half of single element
    // 1st instance = even index
    // 2nd instance = odd index
    
// for right half - 1st instance = odd index & 2nd instance = even index
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right) {
            int mid = (left+right)/2;
            if(((mid%2 == 0) && nums[mid] == nums[mid+1]) || ((mid%2 == 1) && nums[mid] == nums[mid-1])) {
                left = mid+1;
            }
            else right = mid;
        }
        return nums[left];
    }
};