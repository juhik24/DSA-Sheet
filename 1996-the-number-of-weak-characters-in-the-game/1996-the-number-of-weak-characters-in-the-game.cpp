class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[0] != b[0]) {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int ans = 0;
        int mx = INT_MIN;
        int n = properties.size();
        for(int i = 0; i < n; i++) {
            if(mx > properties[i][1]) {
                ans++;
            }
            else mx = properties[i][1];
        }
        return ans;
    }
};