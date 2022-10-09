class Solution {
public:
    // Time = O(nlogn), Space = O(1) 
    
    // Initially low will be matrix[0][0] & high = matrix[n-1][n-1] then we'll find mid
    // Then we'll cnt how many elements are smaller than mid by finding upper bound in every row.
    //if cnt is smaller than k then we'll go in right part (i.e low = mid+1)
    // else if cnt > k then we'll go in left part (i.e, high = mid)
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high) {
            int mid = low+(high-low)/2;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); // time = log n
            }
            if(cnt < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};

// Time = O(n^2 log k), Space = O(n)
    
    // Here we'll store elements in a max pq and if pq.size() becomes greater than k then we'll pop the top element (i.e, greatest element) and pq will contain k smallest element.
    
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         priority_queue<int>pq;  // max pq
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 pq.push(matrix[i][j]);
//                 if(pq.size() > k) {
//                     pq.pop();
//                 }
//             }
//         }
        
//         return pq.top();
//     }