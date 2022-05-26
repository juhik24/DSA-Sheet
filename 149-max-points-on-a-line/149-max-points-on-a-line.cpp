class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1 || n == 2) return n;
        unordered_map<double, int>mp;
        float slope;
        int max = 0;
        for(int i = 0; i < n; i++) {
            int imax=0;
            for(int j = i+1; j < n; j++) {
                if(points[j][0]-points[i][0] == 0) slope = INT_MAX;
                else {
                    slope = (float)(points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0]);
                }
                mp[slope]++;
                if(mp[slope] > imax) imax = mp[slope];
            }
            mp.clear();
            if(imax > max) max = imax;
        }
        return max+1;
    }
};