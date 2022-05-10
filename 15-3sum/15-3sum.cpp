class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int k = 0; k < n; k++) {
            if(k==0 || nums[k] != nums[k-1]) {
                int target = 0-nums[k];
                int i = k+1, j = n-1;
                while(i < j) {
                    if(nums[i]+nums[j] > target) {
                        j--;
                    }
                    else if(nums[i]+nums[j] < target) {
                        i++;
                    }
                    else {
                        v.push_back({nums[k], nums[i], nums[j]});
                        while(i < j && nums[i] == nums[i+1]) {
                            i++;
                        }
                        while(i < j && nums[j] == nums[j-1]) {
                            j--;
                        }
                        i++, j--;
                    }
                }
            }
        }
        return v;
    }
};