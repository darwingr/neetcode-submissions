// Map key -> timestamp:value
//      get finds upper_bound predecessor
//  S(O(vals * keys))
//  get - O(log N)
//  set - O(1)
class TimeMap {
    unordered_map<
        string,
        vector<pair<
            int,
            string>>
    > tm;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!tm.contains(key) || tm[key].empty())
            return "";

        auto series = tm[key];
        size_t l = 0;
        size_t r = series.size();
        while (l < r) {
            size_t mid = l + (r - l) / 2;

            if (series[mid].first <= timestamp)
                l = mid + 1;
            else
                r = mid;
        }
        if (l == 0)
            return "";
        return series[l-1].second;
    }
};
