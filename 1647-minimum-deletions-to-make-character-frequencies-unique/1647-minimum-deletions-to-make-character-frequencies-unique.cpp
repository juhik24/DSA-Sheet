class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        priority_queue<int>pq;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        int cnt=0;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            pq.push(i->second);
        }
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            if(pq.top() == a) {
                if(a-1 > 0) {
                    pq.push(a-1);
                }
                cnt++;
            }
        }
        return cnt;
    }
};