class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                candidate = nums[i];
            }
            if(candidate == nums[i]) cnt++;
            else cnt--;
        }
        return candidate;
    }
};