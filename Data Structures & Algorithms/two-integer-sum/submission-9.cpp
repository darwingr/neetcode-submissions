class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> comp(nums.size());
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            comp[diff] = i;
        }
        for (int j=0; j<nums.size(); j++) {
            if (comp.contains(nums[j]) 
                    && comp[nums[j]] != j)
                return {j, comp[nums[j]]};
        }
    }
};
