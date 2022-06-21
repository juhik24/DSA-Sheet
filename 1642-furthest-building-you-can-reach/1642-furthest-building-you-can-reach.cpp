class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int cnt=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i < n-1; i++) {
            int t = bricks;
            int diff = heights[i+1]-heights[i];
            if(diff > 0) {
                pq.push(diff);
            }
            if(pq.size() > ladders && diff > 0) {
                cnt += pq.top();
                pq.pop();
                t = t - cnt;
            }
            if(t < 0) return i;
        }
        return n-1;
    }
};