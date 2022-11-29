class RandomizedSet {
    unordered_map<int, int> vals;
    vector<int> indxs;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (vals.count(val)) return false;
        vals[val] = indxs.size();
        indxs.push_back(val);
        return true;
    }
    
    bool remove(int val){
        if(!vals.count(val)) return false;
        
        int lst = indxs.back(), pos = vals[val];
        
        vals[lst] = pos;
        indxs[pos] = lst;
        
        vals.erase(val);
        indxs.pop_back();
        
        return true;
    }
    
    int getRandom() {
        return indxs[rand() % indxs.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */