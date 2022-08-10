class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int>st;
        st.push(num[0]);
        for(int i = 1; i < n; i++) {
            while(st.size() > 0 && num[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            if(st.size() > 0 || num[i] != '0') {
                st.push(num[i]);
            }
        }
        while(st.size() > 0 && k--) {
            st.pop();
        }
        if(st.size() == 0) return "0";
        while(!st.empty()) {
            num[n-1] = st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
    }
};