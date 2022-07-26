class SmallestInfiniteSet {
public:
    set<int>s;
    
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int f = 0;
        int ans;
        for(auto i : s) {
            if(f == 0) {
                ans = i;
                s.erase(i);
                f = 1;
                break;
            }
        }
        return ans;
    }
    
    void addBack(int num) {
        s.insert(num);
        cout << num << endl;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */