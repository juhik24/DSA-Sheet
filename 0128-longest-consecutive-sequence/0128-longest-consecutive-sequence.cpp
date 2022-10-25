class Solution {
public:
    // Time = O(n), Space = O(n) 
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        int maxLen = 0;
        for(auto num : s) {
            int len = 1;
           // find consecutive elements in the backward and forward direction from num
            int j = 1, k = 1;
            while(s.find(num-j) != s.end()) {
                s.erase(num-j);
                len++;
                j++;
            }
            while(s.find(num+k) != s.end()) {
                s.erase(num+k);
                len++;
                k++;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

// Time = O(nlogn), Space = O(1) 
    
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 0;
    //     sort(nums.begin(), nums.end());
    //     int len = 1, maxLen = 1;
    //     int ele = nums[0];
    //     for(int i = 1; i < n; i++) {
    //         if(ele+1 == nums[i]) {
    //             ele = ele+1;
    //             len++;
    //         }
    //         else if(ele+1 < nums[i]) {
    //             ele = nums[i];
    //             len = 1;
    //         }
    //         maxLen = max(len, maxLen);
    //     }
    //     return maxLen;
    // }