class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        int mid = (0+n)/2;
        int moves=0;
        for(int i = 0; i <= n; i++) {
            if(i == mid) continue;
            else {
                int a = abs(nums[mid]-nums[i]);
                moves += a;
            }
        }
        return moves;
    }
};