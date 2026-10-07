// Backtrack: dfs, result state
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        res = {};
        if (nums.empty())
            return res;
        ranges::sort(nums);
        vector<int> combo = {};
        dfs(nums, target, combo);
        return res;
    }

    void dfs(vector<int>& nums, int target,
        vector<int>& combo, int i=0)
    {
        if (target == 0) {
            res.push_back(combo);
            return;
        }

        while (i < nums.size()-1 && nums[i] == nums[i+1])
            i++;
        if (i >= nums.size()        // out of bounds
            || target < 0           // bad num
            || nums[i] > target)    // moot to continue, too big
            return;

        // Try i and the next one
        if (nums[i] <= target) {
            combo.push_back(nums[i]);
            dfs(nums, target - nums[i], combo, i);
            combo.pop_back();
        }
        dfs(nums, target, combo, i+1);
    }
};
