class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        stack<int>st;
        int n = gas.size();
        int tot = 0, idx;
        bool f = false;
        for(int i = 0; i < n; i++) {
            tot = tot + (gas[i]-cost[i]);
            if(tot < 0) {
                st.push(tot);
                cout << tot << " ";
                tot = 0;
                f = false;
            }
            else if(f == false && tot >= 0) {
                f = true;
                idx = i;
            }
        }
        cout << endl;
        cout << tot << endl;
        while(st.size() > 0) {
            int a = st.top();
            st.pop();
            tot += a;
            //cout << tot << endl;
            if(tot < 0 && st.size() >= 0) return -1;
        }
        return idx;
    }
};