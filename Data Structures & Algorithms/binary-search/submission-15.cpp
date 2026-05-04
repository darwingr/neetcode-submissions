// O(log N)
// O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t l = 0;
        size_t r = nums.size() - 1;
        while (l<=r && nums[l] <= target && target <= nums[r]) {
            size_t mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
