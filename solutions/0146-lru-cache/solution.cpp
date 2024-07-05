class LRUCache {
public:
    class node {
    public:
        int addr;
        int val;
        node* next;
        node* prev;
        node(int add, int value) {
            addr = add;
            val = value;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int size;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insert(node* newnode) {
        node* agla = head->next;
        newnode->next = agla;
        newnode->prev = head;
        head->next = newnode;
        agla->prev = newnode;
    }

    void remove(node* newnode) {
        node* agla = newnode->next;
        node* pichla = newnode->prev;
        agla->prev = pichla;
        pichla->next = agla;
    }
    int get(int key) {
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;

            m.erase(key);
            remove(resnode);
            insert(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            remove(existingnode);
        }
        if (m.size() == size) {
            m.erase(tail->prev->addr);
            remove(tail->prev);
        }
        insert(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
