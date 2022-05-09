class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, mx = 0, profit = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            if(prices[i] < mn) {
                mn = prices[i];
            }
            else if(prices[i]-mn > mx) {
                profit = profit + (prices[i]-mn);
                mn = prices[i];
                mx = 0;
            }
        }
        return profit;
    }
};