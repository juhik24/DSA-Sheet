class Solution {
    #include<bits/stdc++.h>
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        int count=1;
        for(int i = 0; i < n-1; i++) {
            if(nums[i]!=nums[i+1]) {
                nums[j] = nums[i+1];
                j++;
                count++;
            }
        }
        return count;
    }
};