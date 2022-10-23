class Solution {
public:
    // Time = O(n), Space = O(n) 
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int n = pushed.size();
        int j=0;
        for(int i = 0; i < n; i++) {
            s.push(pushed[i]);
            while(j < n) {
                if(s.empty()) break;
                if(s.top() == popped[j]) {
                    s.pop();
                    j++;
                }
                else break;
            }
            
        }
        if(s.empty()) return true;
        else return false;
    }
};