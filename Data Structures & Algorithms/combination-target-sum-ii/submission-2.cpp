// Backtracking: start, track combo and updated target
//              skip current num when recursing
//  O(2^N)
//  O(N)
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        vector<int> combo;
        if (candidates.front() <= target)
            combo.reserve(target / candidates.front());
        dfs(candidates, target, combo);
        return res;
    }

    void dfs(
        const vector<int>& cans,
        const int target,
        vector<int>& combo,
        int start = 0
    ) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }
        for (int i = start; i<cans.size() && target - cans[i] >= 0; i++) {
            if (i > start && cans[i] == cans[i-1])
                continue;
            combo.push_back(cans[i]);
            dfs(cans, target - cans[i], combo, i + 1);
            combo.pop_back();
        }
    }
};
