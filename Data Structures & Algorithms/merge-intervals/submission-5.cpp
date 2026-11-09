class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals,
            [](auto a, auto b) { return a.front() < b.front(); }
        );
        vector<vector<int>> res;
        res.push_back(intervals.front());
        for (size_t i=1; i<intervals.size(); i++) {
            if (intervals[i].front() > res.back().back())
                res.push_back(intervals[i]);
            else if (intervals[i].back() > res.back().back())
                res.back().back() = intervals[i].back();
        }
        return res;
    }
};
