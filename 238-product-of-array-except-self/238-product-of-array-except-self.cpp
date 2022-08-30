class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n), right(n), ans(n);
        int leftSum;
        left[0] = nums[0];
        for(int i = 1; i < n; i++) {
            leftSum = left[i-1]*nums[i];
            left[i] = leftSum;
        }
        int rightSum;
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightSum = right[i+1]*nums[i];
            right[i] = rightSum;
        }
        ans[0] = right[1];
        ans[n-1] = left[n-2];
        for(int i = 1; i < n-1; i++) {
            ans[i] = left[i-1]*right[i+1];
        }
        return ans;
    }
};