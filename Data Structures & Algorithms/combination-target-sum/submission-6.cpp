class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();

        sort(nums.begin(), nums.end());
        vector<int> combo;
        if (nums.front() <= target)
            combo.reserve(target / nums.front());
        dfs(nums, target, combo);
        return res;
    }

    void dfs(const vector<int>& nums, const int target,
        vector<int>& combo, int start = 0, int sum = 0
    ) {
        if (sum == target) {
            res.push_back(combo);
            return;
        }
        for (int i=start; i<nums.size() && nums[i] <= target-sum; i++) {
            sum += nums[i];
            combo.push_back(nums[i]);
            dfs(nums, target, combo, i, sum);
            combo.pop_back();
            sum -= nums[i];
        }
    }
};
