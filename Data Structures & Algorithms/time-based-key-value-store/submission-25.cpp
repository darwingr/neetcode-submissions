class TimeMap {
    unordered_map<
        string,
        vector<pair<int,string>>> ts_map;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        ts_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!ts_map.contains(key)
            || ts_map[key].empty()
            || ts_map[key].front().first > timestamp)
            return "";
        
        auto& ts = ts_map[key];
        int lo = 0;
        int hi = ts.size();
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (ts[mid].first <= timestamp) // upper bound
                lo = mid + 1;
            else
                hi = mid;
        }
        return ts[lo-1].second;
    }
};
