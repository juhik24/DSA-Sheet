class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto i : mp) {
            pq.push({i.second, i.first});
        }
        int sum = 0, cnt = 0;
        while(sum < n/2) {
            sum += pq.top().first;
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};