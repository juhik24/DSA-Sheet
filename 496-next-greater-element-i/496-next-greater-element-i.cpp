class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int>mp;
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            mp[nums1[i]] = i;
        }
        stack<int>s;
        for(int i = m-1; i >= 0; i--) {
            if(mp.find(nums2[i])!= mp.end()) {
                while(s.size() > 0 && s.top() < nums2[i]) {
                    s.pop();
                }
                int idx = mp[nums2[i]];
                if(s.size() == 0) ans[idx] = -1;
                else ans[idx] = s.top();
            }
            s.push(nums2[i]);
        }
        return ans;
    }
};