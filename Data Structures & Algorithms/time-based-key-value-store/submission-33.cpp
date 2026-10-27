class TimeMap {
    unordered_map<
            string,
            vector<pair<int, string>>
        >ts_map;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        ts_map[key].push_back({timestamp, value});
    }
    
    // find the upper-bound predecessor
    string get(string key, int timestamp) {
        if (!ts_map.contains(key)
                || ts_map[key].empty()
                || ts_map[key].front().first > timestamp)
            return "";
        
        auto& ts = ts_map[key];
        size_t lo = 0;
        size_t hi = ts.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (ts[mid].first <= timestamp)
                lo = mid + 1;
            else
                hi = mid;
        }
        return ts[lo-1].second;
    }
};
