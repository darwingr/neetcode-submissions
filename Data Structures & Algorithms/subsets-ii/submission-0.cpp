class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        res.reserve(1 << nums.size());
        vector<int> path;
        path.reserve(nums.size());
        sort(nums.begin(), nums.end());

        dfs(nums, path);
        return res;
    }

    void dfs(const vector<int>& nums, vector<int>& path, int start=0) {
        res.push_back(path);

        for (int i=start; i<nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            
            path.push_back(nums[i]);
            dfs(nums, path, i + 1);
            path.pop_back();
        }
    }
};
