class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()) {
            int a = s1.top();
            s1.pop();
            s2.push(a);
        }
        int b = s2.top();
        s2.pop();
        while(!s2.empty()) {
            int a = s2.top();
            s2.pop();
            s1.push(a);
        }
        return b;
    }
    
    int peek() {
        while(!s1.empty()) {
            int a = s1.top();
            s1.pop();
            s2.push(a);
        }
        int b = s2.top();
        while(!s2.empty()) {
            int a = s2.top();
            s2.pop();
            s1.push(a);
        }
        return b;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */