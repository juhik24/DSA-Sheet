class LRUCache {
public:
    class node {
        public:
        int val;
        int key;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    
    int cap;
    unordered_map<int, node*>mp;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add_node(node* new_node) {
        node* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }
    
    void delete_node(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            node* res = mp[key];
            int ans = res->val;
            mp.erase(key);
            delete_node(res);
            add_node(res);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            node* existingNode = mp[key];
            mp.erase(key);
            delete_node(existingNode);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */