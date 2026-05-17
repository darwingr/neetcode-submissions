// Map: Key -> (timestamp:value)
//      get finds upper_bound predecessor for timestamp
//
// All timestamps are unique and increasing.
//
// Space: O(keys + timestamps)
// Time:
//  SET - O(1)
//  GET - O(log Timestamps)
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> tm;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!tm.contains(key) || tm[key].front().first > timestamp)
            return "";

        // otherwise it must exist
        auto ts = tm[key];
        int l = 0;
        int r = ts.size() - 1;
        while (l<r) {
            int m = l + (r - l) / 2;
            if (ts[m].first == timestamp)
                return ts[m].second;
            
            if (ts[m].first < timestamp)
                l = m + 1;
            else
                r = m - 1;
        }
        return timestamp < ts[l].first ? ts[l-1].second : ts[l].second;
    }
};
