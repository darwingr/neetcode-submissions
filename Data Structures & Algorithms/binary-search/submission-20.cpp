class Solution {
public:
    // BINARY SEARCH
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid, mid_i;
        while (l <= r)
        {
            mid_i = l + (r - l)/2;
            mid = nums.at(mid_i);
            if (mid < target)
                l = mid_i + 1;
            else if (mid > target)
                r = mid_i - 1;
            else if (mid == target)
                return mid_i;
        }
        return -1;
    }
};