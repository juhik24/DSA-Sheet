class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b) {
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int>pq;
        int sum = 0;
        int n = courses.size();
        for(int i = 0; i < n; i++) {
            if(courses[i][0] <= courses[i][1]) {
                if(sum+courses[i][0] <= courses[i][1]) {
                    sum += courses[i][0];
                    pq.push(courses[i][0]);
                }
                else {
                    if(pq.top() > courses[i][0]) {
                        sum = sum - pq.top();
                        pq.pop();
                        sum +=courses[i][0];
                        pq.push(courses[i][0]);
                    }
                }
            }
        }
        return pq.size();
    }
};