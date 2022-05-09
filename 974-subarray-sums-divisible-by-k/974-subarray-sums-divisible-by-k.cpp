class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum%k;
            if(rem == 0) {
                cnt++;
            }
            else if(rem < 0) {
                rem += k;
            }
            if(mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};