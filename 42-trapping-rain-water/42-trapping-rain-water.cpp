class Solution {
public:
    // Time = O(n), Space = O(n) 
    
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        left[0] = height[0], right[n-1] = height[n-1];
        
        // max in left
        for(int i = 1; i < n; i++) { 
            left[i] = max(left[i-1], height[i]);
        }
        // max in right
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};

// Brute Force: Time = O(n^2), Space = O(1) 

// For every index we'll find the unit of water that will get stored in it.
// For that we need find the max in left and max in right and then basically , min(left, right)- current index
// To find max in left we need to traverse from i to 0 (backwards)
// To find max in right we need to traverse from i to n-1.
// It will create nested loops of (n^2)