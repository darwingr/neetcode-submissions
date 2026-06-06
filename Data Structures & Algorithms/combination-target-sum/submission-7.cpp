// Backtracking: dfs, track combo, target & start
//
//  O(N x 2^(T/N))
//  O(2^(t/n))
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        res.reserve(1 << nums.size()); // 2^N
        
        vector<int> combo;
        sort(nums.begin(), nums.end());
        if (nums.front() <= target)
            combo.reserve(target / nums.front());
        
        dfs(nums, target, combo);
        return res;
    }

    void dfs(
        const vector<int>& nums,
        int target,
        vector<int>& combo,
        int start=0
    ) {
        if (target == 0) {
            res.push_back(combo);
            return;
        }

        for (int i=start; i<nums.size() && target - nums[i] >= 0; i++) {
            combo.push_back(nums[i]);
            dfs(nums, target - nums[i], combo, i);
            combo.pop_back();
        }
    }
};
