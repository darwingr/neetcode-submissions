// Iter 3 options: completely before, overlapping, completely after
//      Init result with newInterval, swapping as you go
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{{newInterval}};
        for (auto& inter : intervals) {
            int start_i = inter.front();
            int end_i = inter.back();
            // completely before
            if (res.back().back() < start_i)
                res.push_back(inter);
            // completely after
            else if (end_i < res.back().front()) {
                res.push_back(inter);
                swap(res.back(), res[res.size()-2]);
            }
            // overlapping
            else {
                res.back().front() = min(res.back().front(), start_i);
                res.back().back()  = max(res.back().back(),  end_i);
            }
        }
        return res;
    }
};
