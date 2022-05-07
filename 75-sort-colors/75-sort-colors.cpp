class Solution {
public:
    int Partition(vector<int>&nums, int start, int end) {
        int pivot = nums[end];
        int partitionIndex = start;
        for(int i = start; i < end; i++) {
            if(nums[i] <= pivot) {
                swap(nums[i], nums[partitionIndex]);
                partitionIndex++;
            }
        }
        swap(nums[end], nums[partitionIndex]);
        return partitionIndex;
    }
    
    void QuickSort(vector<int>& nums, int start, int end) {
        if(start < end) {
            int partitionIndex = Partition(nums, start, end);
            QuickSort(nums, start, partitionIndex-1);
            QuickSort(nums, partitionIndex+1, end);
        }
    }
    
    void sortColors(vector<int>& nums) {
         int n = nums.size();
         int start = 0;
         int end = n-1;
         QuickSort(nums, start, end);
    }
};