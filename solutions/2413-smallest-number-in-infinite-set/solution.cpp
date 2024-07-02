class SmallestInfiniteSet {
public:
    int cur = 1;
    set<int> added; 
    int popSmallest() {
        if (!added.empty()) {
            int res = *added.begin();
            added.erase(res);
            return res;
        }
        cur++;
        return cur-1;
    }
    void addBack(int num) {
        if (num < cur)
            added.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
