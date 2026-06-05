// Backtracking: add current path then explore extensions,
//               track start and path/subset
class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        res.reserve(1 << nums.size());

        vector<int> path;
        
        dfs(nums, path);
        return res;
    }

    void dfs(const vector<int>& nums, vector<int>& path, int start=0) {
        res.push_back(path);

        for (int i=start; i<nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, path, i + 1);
            path.pop_back();
        }
    }
};
