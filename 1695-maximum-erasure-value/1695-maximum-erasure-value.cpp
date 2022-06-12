class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int>s;
        for(int i = 0, j = 0, window = 0; j < n; j++) {
            while(s.find(nums[j]) != s.end()) {
                s.erase(nums[i]);
                window = window-nums[i];
                i++;
            }
            s.insert(nums[j]);
            window = window + nums[j];
            ans = max(ans, window);
        }
        return ans;
    }
};