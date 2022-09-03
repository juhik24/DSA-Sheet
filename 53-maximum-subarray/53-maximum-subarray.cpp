class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};

//Brute force - time = O(n^2), space = O(1);

// int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int maxSum = INT_MIN;
//         for(int i = 0; i < n; i++) {
//             int sum = 0;
//             for(int j = i; j < n; j++) {
//                 sum += nums[j];
//                 maxSum = max(maxSum, sum);
//             }
//         }
//         return maxSum;
//     }