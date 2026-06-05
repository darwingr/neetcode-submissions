// Iteration
//  O(N x 2^N)
//  SPACE:
//      O(N) extra
//      O(N x 2^N) total
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.reserve(1 << nums.size());
        res.push_back({});
        for (int n : nums) {
            int res_size = res.size();
            for (size_t i=0; i<res_size; i++) {
                vector<int> res_subset = res[i];
                res_subset.push_back(n);
                res.push_back(res_subset);
            }
        }
        return res;
    }
};
