class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_water = INT_MIN;
        int i = 0, j = n-1;
        while(i < j) {
            int width = j-i;
            int ht = min(height[i], height[j]);
            int vol = width*ht;
            max_water = max(max_water, vol);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return max_water;
    }
};