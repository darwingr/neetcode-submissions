// Backtracking == permutations
//  
//  O(N x N!)
//  O(N)
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        unordered_set<int> visited;
        visited.reserve(nums.size());
        vector<int> perm;
        perm.reserve(nums.size());

        dfs(nums, visited, perm);
        return res;
    }

    void dfs(const vector<int>& nums, unordered_set<int>& visited, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int n : nums) {
            if (visited.contains(n))
                continue;
            visited.insert(n);
            perm.push_back(n);
            dfs(nums, visited, perm);
            perm.pop_back();
            visited.erase(n);

        }
    }
};
