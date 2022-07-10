class Solution {
public:
    void solve(vector<vector<int>>&image, int sr, int sc, int color, int a) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != a) return;
        image[sr][sc] = color;
        solve(image, sr-1, sc, color, a);
        solve(image, sr+1, sc, color, a);
        solve(image, sr, sc-1, color, a);
        solve(image, sr, sc+1, color, a);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int a = image[sr][sc];
        if(color == a) return image;
        solve(image, sr, sc, color, a);
        return image;
    }
};