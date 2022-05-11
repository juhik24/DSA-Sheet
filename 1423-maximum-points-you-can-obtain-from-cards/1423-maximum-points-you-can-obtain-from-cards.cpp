class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_score = INT_MIN;
        int score = 0;
        for(int i = 0; i < n; i++) {
            score += cardPoints[i];
        }
        if(n == k) return score;
        int window = 0;
        for(int i = 0; i < n-k-1; i++) {
            window += cardPoints[i];
        }
        for(int i = n-k-1; i < n; i++) {
            window += cardPoints[i];
            if(score-window > max_score) {
                max_score = score-window;
            }
            window -= cardPoints[i-(n-k-1)];
        }
        return max_score;
    }
};