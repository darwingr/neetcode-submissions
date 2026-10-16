//  O(log N)
//  O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t left = 0;
        size_t right = nums.size();
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (left == nums.size() || nums[left] != target)
            return -1;
        return left;
    }
};
