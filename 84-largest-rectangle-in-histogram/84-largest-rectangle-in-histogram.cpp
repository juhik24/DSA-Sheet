class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int lb[n], rb[n];
        stack<int>st;
        rb[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.size() == 0) rb[i] = n;
            else rb[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        lb[0] = -1;
        st.push(0);
        for(int i = 1; i < n; i++) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.size() == 0) lb[i] = -1;
            else {
                lb[i] = st.top();
            }
            st.push(i);
        }
        int max_area = INT_MIN;
        for(int i = 0; i < n; i++) {
            int width = rb[i] - lb[i] - 1;
            int area = width * heights[i];
            if(area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};