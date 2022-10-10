class Solution {
public:
    // Time = O(nlogn), Space = O(n) 
    
    class ds {
        public:
          int start;
          int end;
          int pos;
    };
    
    static bool cmp(ds a, ds b) {
        if(a.end < b.end) {
            return true;
        }
        else if(a.end > b.end) return false;
        else if(a.pos < b.pos) return true;
        return false;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        ds arr[n];
        for(int i = 0; i < n; i++) {
            arr[i].start = intervals[i][0];
            arr[i].end = intervals[i][1];
            arr[i].pos = i+1;
        }
        sort(arr, arr+n, cmp);
        int limit = arr[0].end;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i].start >= limit) {
                limit = arr[i].end;
                cnt++;
            }
        }
        return n-cnt;
    }
};