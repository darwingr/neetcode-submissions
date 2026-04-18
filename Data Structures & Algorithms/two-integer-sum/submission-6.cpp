// Hash diffs, math
//  O(N)
//  O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff_idx;
        for (int i=0; i<nums.size(); i++) {
            if (diff_idx.contains(nums[i]))
                return { diff_idx[nums[i]], i };
            int diff = target - nums[i];
            diff_idx[diff] = i;
        }
    }
};
