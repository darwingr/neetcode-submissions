// Backtracking, early stop
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        ranges::sort(nums);
        res = {};
        vector<int> combo = {};
        dfs(nums, target, combo);
        return res;
    }

    void dfs(vector<int>& nums, int target,
             vector<int>& combo, int pos=0)
    {
        if (nums[pos] == target) {
            combo.push_back(nums[pos]);
            res.push_back(combo);
            combo.pop_back();
        }
        else if (nums[pos] < target) {
            combo.push_back(nums[pos]);
            dfs(nums, target - nums[pos], combo, pos);
            combo.pop_back();
            if (pos+1 < nums.size())
                dfs(nums, target, combo, pos+1);
        }
    }
};
