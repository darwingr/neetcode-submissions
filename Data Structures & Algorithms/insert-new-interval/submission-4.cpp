class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{newInterval};
        res.reserve(intervals.size() + 1);

        for (auto& inter : intervals) {
            int last_start = res.back().front();
            int last_end = res.back().back();

            if (last_end < inter[0])
                res.push_back(inter);
            else if (inter[1] < last_start) {
                swap(res.back(), inter);
                res.push_back(inter);
            }
            else // overlapping
                res.back() = {
                    min(last_start, inter[0]),
                    max(last_end,   inter[1])
                };
        }
        return res;
    }
};
