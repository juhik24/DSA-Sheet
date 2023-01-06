class Solution {
public:
// Time = O(nlogn), Space = O(1)

    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int cnt = 0;
        sort(costs.begin(), costs.end());
        for(int i = 0; i < n; i++) {
            if(coins < costs[i]) break;
            else {
                cnt++;
                coins = coins - costs[i];
            }
        }
        return cnt;
    }
};