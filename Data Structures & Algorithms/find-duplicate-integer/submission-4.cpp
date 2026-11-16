// fast/slow & 3rd trailing pointer
//  O(n)
//  O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count = nums.size();
        size_t slow = 0;
        size_t fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);

        size_t trail = 0;
        do {
            slow = nums[slow];
            trail = nums[trail];
        } while (slow != trail);

        return slow;
    }
};
