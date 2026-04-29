// Track Starts, JOIN or EXTEND
//  NOT O(N)
//  O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> start_indices;

        // 3 options: extend, begin, join
        for (int i=0; i<nums.size(); i++) {
            if (start_indices.contains(nums[i]))
                continue;
            start_indices[nums[i]] = i;
            int prev = nums[i] - 1;
            int next = nums[i] + 1;
            if (start_indices.contains(prev))
                start_indices[nums[i]] = start_indices[prev];
            if (start_indices.contains(next))
                start_indices[next] = start_indices[nums[i]];
        }

        int biggest = 0;
        for (auto [val, start_i] : start_indices) {
            if (val == nums[start_i]) {
                int end_val = val;
                while (start_indices.contains(++end_val)) {}
                int diff = end_val - val;
                biggest = max(diff, biggest);
            }
        }
        return biggest;
    }
};
