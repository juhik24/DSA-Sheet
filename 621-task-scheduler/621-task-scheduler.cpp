class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int>mp;
        for(int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        for(auto i : mp) {
            pq.push(i.second);
        }
        queue<pair<int, int>>q;
        while(!pq.empty() || !q.empty()) {
            time++;
            int cnt;
            if(pq.size() > 0) {
                cnt = pq.top()-1;
                pq.pop();
                if(cnt > 0) q.push({cnt, time+n});
            }
            if(q.size() > 0 && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};