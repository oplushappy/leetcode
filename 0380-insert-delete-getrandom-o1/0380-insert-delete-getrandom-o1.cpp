class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valToIdx;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToIdx.count(val)) return false;
        nums.push_back(val);
        valToIdx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!valToIdx.count(val)) return false;
        int idx = valToIdx[val];
        int last = nums.back();

        nums[idx] = last;
        valToIdx[last] = idx;
        
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */