class Solution {
public:
    // Time = O(nlogn)->worst case, O(klog n)->average case, Space = O(n) 
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto i : mp) {
            pq.push({i.second, i.first});
            cout << i.second << i.first << endl;
        }
        vector<int>ans;
        for(int i = 0; i < k; i++) {
            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
        }
        return ans;
    }
};