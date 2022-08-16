class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        st.push(asteroids[0]);
        for(int i = 1; i < n; i++) {
            while(st.size() > 0 && asteroids[i] < 0 && st.top() > 0) {
                int a = st.top() + asteroids[i];
                if(a < 0) {
                    st.pop();
                }
                else if( a > 0) {
                    asteroids[i] = 0;
                }
                else {
                    asteroids[i] = 0;
                    st.pop();
                }
            }
            if(asteroids[i] != 0) {
                st.push(asteroids[i]);
            }
        }
        vector<int>ans(st.size());
        int l = st.size()-1;
        while(st.size() > 0) {
            int a = st.top();
            st.pop();
            ans[l] = a;
            l--;
        }
        return ans;
    }
};