class RandomizedSet {
private:
    vector<int> myvec;
    map<int, int> mymap;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        for (auto & x : mymap)
            mymap.erase(x.first);
        myvec.clear();
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mymap.count(val)) return false;
        myvec.push_back(val);
        mymap[val] = size;
        ++size;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mymap.count(val) == 0) return false;
        myvec[mymap[val]] = myvec.back();
        mymap[myvec.back()] = mymap[val];
        myvec.pop_back();
        --size;
        mymap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return myvec[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */