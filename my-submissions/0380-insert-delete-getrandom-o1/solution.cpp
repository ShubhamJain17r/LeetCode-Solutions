class RandomizedSet {
        unordered_set<int> s;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (s.find(val) == s.end()){
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (s.find(val) != s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if (s.empty()) return -1;
    
        size_t index = std::rand() % s.size();
        return *std::next(s.begin(), index);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
