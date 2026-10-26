class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t lo = 0;
        size_t hi = nums.size();
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (lo >= nums.size() || nums[lo] != target)
            return -1;

        return lo;
        
    }
};
