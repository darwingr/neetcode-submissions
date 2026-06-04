// Iteration
//  O(N x 2^N)
//  O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        res.reserve(1 << nums.size());
        for (int num : nums) {
            int size = res.size();
            for (int i=0; i<size; i++) {
                auto subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};
