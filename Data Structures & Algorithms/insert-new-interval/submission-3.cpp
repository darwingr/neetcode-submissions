// New goes first then iterate: each goes relative to last either
//      completely after, completely before, overlapping
//  O(N)
//  O(1) extra
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{newInterval};

        for (auto inter : intervals) {
            if (res.back().back() < inter.front())
                res.push_back(inter);
            else if (inter.back() < res.back().front()) {
                res.push_back(inter);
                swap(res.back(), res[res.size()-2]);
            } else {// overlap
                res.back().front() = min(res.back().front(), inter.front());
                res.back().back()  = max(res.back().back(),  inter.back());
            }
        }
        return res;
    }
};
