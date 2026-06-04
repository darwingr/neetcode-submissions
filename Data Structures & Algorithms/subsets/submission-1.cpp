// DFS with backtracking. Shared result set.
//  O(N x 2^N)
//  O(N) extra space...this is a lie, consider stack space.
class Solution {
    vector<vector<int>> res;
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        //int subset_count = pow(2, nums.size());
        int subset_count = 1 << nums.size();
        res.reserve(subset_count);
        
        vector<int> subset;
        dfs(nums, 0, subset);
        return res;
    }

    void dfs(const vector<int>& nums, int i, vector<int>& subset) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i+1, subset);
        subset.pop_back();
        dfs(nums, i+1, subset);
    }
};
