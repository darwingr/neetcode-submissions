//  O(2^(T/N))
//  O(T/N)
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        int max_combos = 1 << (target / nums.size());
        res.reserve(max_combos);
        
        vector<int> subset;
        subset.reserve(target / nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums, target, subset);

        return res;
    }

    void dfs(const vector<int>& nums, const int target,
            vector<int>& subset, int sum = 0, size_t start_i = 0)
    {
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        for (size_t i=start_i;
            i<nums.size()
                && sum + nums[i] <= target;
            i++)
        {
            sum += nums[i];
            subset.push_back(nums[i]);
            dfs(nums, target, subset, sum, i);
            sum -= nums[i];
            subset.pop_back();
        }
    }
};
