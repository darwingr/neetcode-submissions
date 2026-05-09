// Time-ordered maps
//  append only?
#include <ranges>
#include <cassert>
class TimeMap {
    // Key->Vector of Timestamp:Value
    //  O(M * N) - keys x values
    unordered_map<
        string,
        vector<
            pair<int, string>
        >
    > tm;
public:
    TimeMap() {}
    
    // O(1) - must be append only, with increasing timestamps only
    void set(string key, string value, int timestamp) {
        // sanity check for append only property
        //if (tm.contains(key))
        //    assert(tm[key].empty() || tm[key].back().first <= timestamp);

        tm[key].emplace_back(timestamp, value);
        //auto& series = tm[key];
        //series.push_back({timestamp, value});
    }
    
    // O(log N)
    string get(string key, int timestamp) {
        if (!tm.contains(key))
            return "";
        
        auto& series = tm[key];

        // Binary Search for "on or before" timestamp
        //  predecessor of upper_bound
        size_t l = 0;
        size_t r = series.size();
        string val = "";

        while (l<r) {
            size_t mid = l + (r - l) / 2;

            // ASSUMES no duplicate timestamps
            if (series[mid].first <= timestamp) {
                val = series[mid].second;
                l = mid + 1;
            }
            else
                r = mid;
        }
        return val;
    }
};
