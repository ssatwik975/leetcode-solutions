class RandomizedSet {
public:
    unordered_set<int> ds;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(ds.find(val) == ds.end()){
            ds.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(ds.find(val) != ds.end()){
            ds.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return *next(ds.begin(),rand()%ds.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
