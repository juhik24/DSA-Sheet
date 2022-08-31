class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n; k++) {
            if(k == 0 || nums[k] != nums[k-1]) {
                int i = k+1, j = n-1;
                int target = 0-nums[k];
                while(i < j) {
                    if(nums[i]+nums[j] < target) {
                        i++;
                    }
                    else if(nums[i]+nums[j] > target) {
                        j--;
                    }
                    else {
                        ans.push_back({nums[k], nums[i], nums[j]});
                        while((i < j) && nums[i] == nums[i+1]) {
                            i++;
                        }
                        while((i < j) && nums[j] == nums[j-1]) {
                            j--;
                        }
                        i++; j--;
                    }
                }
            }
        }
        return ans;
    }
};