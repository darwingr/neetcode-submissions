// Backtracking: dfs, res, combo param, pruning
//  O(n * 2^n)
//  O(n)
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res = {};
        ranges::sort(candidates);
        vector<int> combo = {};
        dfs(candidates, target, combo);
        return res;
    }

    void dfs(vector<int>& nums, int target, vector<int>& combo, int pos=0) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }

        for (int i=pos; i<nums.size(); i++) {
            if (nums[i] > target)
                break;
            if (i > pos && nums[i] == nums[i-1])
                continue;
            
            combo.push_back(nums[i]);
            dfs(nums, target-nums[i], combo, i+1);
            combo.pop_back();
        }
    }
};
