// O(N)
// O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int last = -1;
        int before_last = -1;

        int best = nums.back();
        for (int i=nums.size()-1; i>=0; i--) {
            best = max(
                nums[i] + max(0, before_last),
                max(0, last)
            );
            before_last = last;
            last = best;
        }
        return best;
    }
};