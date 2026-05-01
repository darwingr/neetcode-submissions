// Greedy: start from back
//  O(N)
//  O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size() - 1;
        int last = i;
        while (i > 0) {
            --i;
            if (nums[i] >= last - i)
                last = i;
        }
        return i + nums[i] >= last;
    }
};
