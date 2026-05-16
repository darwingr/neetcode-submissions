// Use time map of key -> vec(timestamp:vaue)
//      timestamps guaranteed in order and no duplicates
//  Space: O(K + V)
//  set: O(1)
//  get: O(log uniq(V))
#include <ranges>
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> tm;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!tm.contains(key))
            return "";

        auto ts = tm[key];
        // find upper_bound predecessor
        auto ub_it = ranges::upper_bound(ts, timestamp, {},  &pair<int,string>::first);
        //auto ub_it = ranges::upper_bound(
        //    ts.begin(),
        //    ts.end(),
        //    {timestamp, ""});
        if (ub_it == ts.begin())
            return "";
        auto pred_it = prev(ub_it);
        auto [_, val] = *pred_it;
        return val;
    }
};
