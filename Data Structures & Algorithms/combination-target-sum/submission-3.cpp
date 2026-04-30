// Backtracking: 
//  time  O(2 ^ target / min_val)
//  space O(target / min_val)
class Solution {
    vector<vector<int>> all_combos;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        all_combos = {};
        vector<int> running_combo;
        dfs(nums, target, running_combo);
        return all_combos;
    }

    void dfs(vector<int>& nums, int target, vector<int>& combo) {
        for (int n : nums) {
            if (target - n < 0)
                break;
            if (!combo.empty() && combo.back() > n)
                continue;
            
            combo.push_back(n);
            if (target - n == 0)
                all_combos.push_back(combo);
            else
                dfs(nums, target - n, combo);
            combo.pop_back();
        }
    }
};
