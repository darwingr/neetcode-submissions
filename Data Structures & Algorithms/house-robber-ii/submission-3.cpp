// O(N)
// O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.front();
        else if (nums.size() == 2)
            return max(nums.front(), nums.back());
        
        return max(
            rob(nums, 0),
            rob(nums, 1)
        );
    }

private:
    int rob(vector<int>& nums, int start) {
        int size = nums.size() - 1;
        int last = -1;
        int before_last = -1;

        int best;
        for (int i = start+size-1; i>=start; i--) {
            best = max(
                max(0, last),
                nums[i] + max(0, before_last)
            );
            before_last = last;
            last = best;
        }
        return best;
    }
};
