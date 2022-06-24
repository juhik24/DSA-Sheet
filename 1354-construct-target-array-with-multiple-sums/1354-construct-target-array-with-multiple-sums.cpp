class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<int>pq;
        long sum = 0;
        for(int i = 0; i < n; i++) {
            pq.push(target[i]);
            sum += target[i];
        }
        while(pq.top() != 1) {
            sum = sum-pq.top();
            if(sum >= pq.top() || sum <= 0 ) return false;
            int a = pq.top()%sum;
            sum += a;
            pq.pop();
            if(a > 0) pq.push(a);
            else pq.push(sum);
        }
        return true;
    }
};