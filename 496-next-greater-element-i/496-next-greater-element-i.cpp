class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int>mp;
        vector<int>ans(n, -1);
        for(int i = 0; i < n; i++) {
            mp[nums1[i]] = i;
        }
        for(int i = 0; i < m; i++) {
            if(mp.find(nums2[i]) == mp.end()) continue;
            else {
                for(int j = i+1; j < m; j++) {
                    if(nums2[j] > nums2[i]) {
                        int idx = mp[nums2[i]];
                        ans[idx] = nums2[j];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};