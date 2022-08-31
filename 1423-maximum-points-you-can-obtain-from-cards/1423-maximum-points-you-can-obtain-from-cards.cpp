class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_points = INT_MIN;
        int window = 0, score = 0;
        for(int i = 0; i < n; i++) {
            score += cardPoints[i];
        }
        if(n == k) return score;
        for(int i = 0; i < n-k-1; i++) {
            window += cardPoints[i];
        }
        for(int i = n-k-1; i < n; i++) {
            window += cardPoints[i];
            if(score - window > max_points) {
                max_points = score - window;
            }
            window -= cardPoints[i-(n-k-1)];
        }
        return max_points;
    }
};