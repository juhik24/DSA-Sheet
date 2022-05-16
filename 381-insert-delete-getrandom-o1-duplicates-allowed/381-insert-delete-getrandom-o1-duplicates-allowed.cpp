class RandomizedCollection {
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> A;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        nums.clear();
        A.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = A.find(val)==A.end();
        A[val].push_back(nums.size()); //push_back indexes in nums
        nums.push_back(make_pair(val, A[val].size()-1)); //1st- value itself, 2nd- index in the map
        return ret;       
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool ret = A.find(val)!=A.end();
        if(ret)
        {
            auto last = nums.back();
            A[last.first][last.second] = A[val].back();
            nums[A[val].back()] = last;
            A[val].pop_back();
            if(A[val].empty())
                A.erase(val);
            nums.pop_back();
        }
        return ret;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()].first;
    }
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */