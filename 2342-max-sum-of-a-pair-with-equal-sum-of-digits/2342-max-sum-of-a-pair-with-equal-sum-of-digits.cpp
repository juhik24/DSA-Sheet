class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int a = nums[i];
            int digit = 0;
            while(a!= 0) {
                int b = a%10;
                digit += b;
                a = a/10;
            }
            mp[digit].push(nums[i]);
        }
        priority_queue<int>ans;
        for(auto i : mp) {
            int sum = i.first;
            priority_queue<int>pq = i.second;
            if(pq.size() > 1) {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                ans.push(a+b);
            }
        }
        if(ans.size() > 0) return ans.top();
        return -1;
    }
};