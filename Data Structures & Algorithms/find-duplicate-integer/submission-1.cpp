// negate values at corresponding index as a
//  O(N)
//  O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for (int i=0; i<nums.size();i++) {
            int val = abs(nums[i]);
            if (nums[val] < 0)
                return val;
            else
                nums[val] *= -1;
        }
        return 0;
    }
};
