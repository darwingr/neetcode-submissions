// Bin Search: consider deflection and range
//      Dont offset mid on conditionals, only actions.
//      First consider sorted sides
//  O(log N)
//  O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            // left sorted
            if (nums[l] <= nums[mid]) {
                if (target < nums[l] || target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {// right sorted
                if (target < nums[mid] || target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};
