class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>>p;
        int max_value = INT_MIN;
        for(int i = 0; i < n; i++) {
            while(!p.empty() && points[i][0] - p.top().second > k) {
                p.pop();
            }
            if(!p.empty()) {
                int val = points[i][0]+points[i][1]+p.top().first;
                max_value = max(max_value, val);
            }
            p.push({points[i][1]-points[i][0], points[i][0]});
        }
        return max_value;
    }
};