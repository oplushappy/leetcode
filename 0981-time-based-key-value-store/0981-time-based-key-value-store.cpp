class TimeMap {
public:
    template<typename T, typename M>
    T get_first_match(T lo, T hi, M match) {
        while(lo <= hi) {
            T mid = lo + (hi - lo) / 2;
            if(match(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    };

    unordered_map<string, vector<pair<int, string>>> timemap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        int n = timemap[key].size();
        int res = get_first_match(0, n - 1, [&](int idx) {
            return timemap[key][idx].first > timestamp;
        });
        if((res - 1) >= 0) return timemap[key][res - 1].second;
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */