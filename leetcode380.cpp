class RandomizedSet {
    unordered_map<int,int> hp;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hp.count(val)){
            return false;
        }
        
        hp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!hp.count(val)){
            return false;
        }
        
        int pos = hp[val];
        v[pos] = v.back();
        v.pop_back();
        
        
        hp[v[pos]] = pos;
        hp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */