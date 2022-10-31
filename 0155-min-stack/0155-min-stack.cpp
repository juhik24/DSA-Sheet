class MinStack {
public:
    // Time = O(1), Space = O(N) or O(2N)
    
    // Here we are creating a stack of pairs and pair will contain the current value and min. element till now.
    
    vector<pair<int, int>>v;
    
    MinStack() {
    
    }
    
    void push(int val) {
        int size = v.size();
        if(size == 0) {
            v.push_back({val, val});
        }
        else {
            if(v[size-1].second < val) {
                v.push_back({val, v[size-1].second});
            }
            else {
                v.push_back({val, val});
            }
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        int size = v.size();
        return v[size-1].first;
    }
    
    int getMin() {
        int size = v.size();
        return v[size-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */