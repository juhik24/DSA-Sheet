class Solution {
public:
    // Time = O(nlogL)-> L = ladders, Space = O(L)
    
    // We'll create a min priority queue and maintain a variable bricksUsed.
    // Whenever we see the next building is greater(i.e, the diff of current building & next building is greater than 0 then we'll store the diff in priority queue)
    // If pq.size() becomes greater than no. of ladders then we'll pop the top element from pq (i.e, min diff) and add it to bricksUsed.
    // If bricksUsed becomes greater than no. of bricks then we'll return that index, because that will be the last index.
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>>pq;  // min priority queue
        int bricksUsed = 0;
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff > 0) {
                pq.push(diff);
                if(pq.size() > ladders) {
                    bricksUsed += pq.top();
                    pq.pop();
                }
                if(bricksUsed > bricks) {
                    return i-1;
                }
            }
        }
        return n-1;
    }
};