class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        unordered_map<char, int>mp;
        priority_queue<int>pq;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for(auto i : mp) {
            pq.push(i.second);
        }
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            if(a == pq.top()) {
                if(a-1 > 0) {
                    pq.push(a-1);
                }
                cnt++;
            }
        }
        return cnt;
    }
};