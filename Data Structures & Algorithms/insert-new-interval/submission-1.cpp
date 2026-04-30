// Iter 3 options: completely before, overlapping, completely after
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result{{newInterval}};
        for (int i=0; i<intervals.size(); i++) {
            int start_i = intervals[i].front();
            int end_i = intervals[i].back();
            // completely before
            if (result.back().back() < start_i)
                result.push_back(intervals[i]);
            // completely after
            else if (end_i < result.back().front()) {
                result.push_back(intervals[i]);
                swap(result.back(), result[result.size()-2]);
            }
            // overlapping
            else {
                result.back().front() = min(result.back().front(), start_i);
                result.back().back()  = max(result.back().back(),  end_i);
            }
        }
        return result;
    }
};
