class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0; i < numRows; i++) {
            vector<int>v;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    v.push_back(1);
                    continue;
                }
                int a = ans[i-1][j-1]+ans[i-1][j];
               v.push_back(a);
            }
            ans.push_back(v);
        }
        return ans;
    }
};