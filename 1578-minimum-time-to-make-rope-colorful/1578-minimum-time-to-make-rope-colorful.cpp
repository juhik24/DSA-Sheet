class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        stack<pair<char, int>>st;
        st.push({colors[0], neededTime[0]});
        int time = 0;
        for(int i = 1; i < n; i++) {
            if(st.top().first == colors[i]) {
                if(neededTime[i] <= st.top().second) {
                    time += neededTime[i];
                }
                else {
                    time += st.top().second;
                    st.pop();
                    st.push({colors[i], neededTime[i]});
                }
            }
            else st.push({colors[i], neededTime[i]});
        }
        return time;
    }
};