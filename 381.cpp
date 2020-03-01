class RandomizedCollection {
private:
    vector<int> myvec;
    unordered_map<int, unordered_set<int>> mymap;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        for (auto & x : mymap)
            mymap.erase(x.first);
        myvec.clear();
        size = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        myvec.push_back(val);
        ++size;
        if (mymap.count(val)) {
            mymap[val].insert(size - 1);
            return false;
        }            
        else 
            mymap[val] = unordered_set<int>{size - 1};
                    
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mymap.count(val) == 0) return false;
        auto pos = *(mymap[val].begin());
        
        myvec[pos] = myvec.back();
        mymap[val].erase(pos);
        mymap[myvec.back()].insert(pos);
        mymap[myvec.back()].erase(size - 1);
        myvec.pop_back();
        --size;
        
        if (mymap[val].size() == 0) 
            mymap.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return myvec[rand() % size];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */