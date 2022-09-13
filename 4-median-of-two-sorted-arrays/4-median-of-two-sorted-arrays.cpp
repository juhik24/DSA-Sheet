class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>v(m+n);
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                v[k] = nums1[i];
                i++;
            }
            else {
                v[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < n) {
            v[k] = nums1[i];
            k++; i++;
        }
        while(j < m) {
            v[k] = nums2[j];
            k++; j++;
        }
        return v;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = merge(nums1, nums2);
        int n = v.size();
        if(n%2 == 0) {
            int m1 = n/2;
            int m2 = m1-1;
            int med = (v[m1]+v[m2])*1.0/2.0;
            if((v[m1]+v[m2])%2 > 0) {
                return med+0.5;
            }
            else return med;
        }
        else  {
            int m = n/2;
            return v[m]*1.0;
        }
    }
};