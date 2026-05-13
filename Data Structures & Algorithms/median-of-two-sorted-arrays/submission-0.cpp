//  O(log(M + N))
//  O(1)
#include <ranges>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto n = vector<int>(nums1.size() + nums2.size());
        ranges::merge(nums1, nums2, n.begin());
        size_t mid = n.size() / 2;
        if (n.size() % 2 == 0)
            return (n[mid-1] + n[mid]) / 2.0;
        else
            return n[mid];
    }
};
