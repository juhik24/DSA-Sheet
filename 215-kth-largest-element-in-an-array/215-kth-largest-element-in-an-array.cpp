class Solution {
public:
    // Time = O(n), Space = O(n) 
    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for(int i = 0; i < k-1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

// Time = O(nlogn), Space = O(1) 

// int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     return nums[n-k];
    // }