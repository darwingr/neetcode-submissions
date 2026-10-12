class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res = {};
        ranges::sort(nums);
        vector<int> combo = {};
        dfs(nums, target, combo);
        return res;
    }

    void dfs(vector<int>& nums, int target, vector<int>& combo, int index = 0) {
        // bounds
        if (index >= nums.size() || index < 0)
            return;

        while (index < nums.size()-1 && nums[index] == nums[index+1])
            index++;

        if (nums[index] < target) {
            combo.push_back(nums[index]);
            dfs(nums, target - nums[index], combo, index);
            combo.pop_back();
            dfs(nums, target, combo, index+1);
        } else if (nums[index] == target) {
            combo.push_back(nums[index]);
            res.push_back(combo);
            combo.pop_back();
            return;
        } else {
            return;
        }
    }
};
