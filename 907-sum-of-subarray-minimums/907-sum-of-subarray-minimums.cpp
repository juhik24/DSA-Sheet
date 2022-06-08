class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int m = (int)1e9+7;
        int n = arr.size();
        long left[n];
        long right[n];
        stack<pair<int, int>>s1, s2;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            while(s1.size() > 0 && s1.top().first > arr[i]) {
                cnt += s1.top().second;
                s1.pop();
            }
            s1.push({arr[i], cnt});
            left[i] = cnt;
        }
        for(int i = n-1; i >= 0; i--) {
            int cnt = 1;
            while(s2.size() > 0 && s2.top().first >= arr[i]) {
                cnt += s2.top().second;
                s2.pop();
            }
            s2.push({arr[i], cnt});
            right[i] = cnt;
        }
        for(int i = 0; i < n; i++) {
            sum = (sum+(arr[i]*(left[i]*right[i])%m)%m)%m;
        }
        return sum%m;
    }
};