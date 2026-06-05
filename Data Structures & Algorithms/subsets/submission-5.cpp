// Bitwise and mask
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subset_count = 1 << nums.size();
        vector<vector<int>> res;
        res.reserve(subset_count);
        
        for (int subset_index = 0; subset_index < subset_count; subset_index++) {
            vector<int> subset;
            for (int i=0; i<nums.size(); i++) {
                int nums_mask = 1 << i; // 2^i
                bool include_num_i = subset_index & nums_mask;
                if (include_num_i)
                    subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }
        return res;
    }
};
