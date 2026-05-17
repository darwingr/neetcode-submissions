// How many of A are in the first half?
//  O(log( min(N, M)))
//  O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int cut1 = (l + r) / 2; // mid1
            int cut2 = half - cut1;

            int l1 = cut1 > 0 ? nums1[cut1 - 1] : INT_MIN;
            int r1 = cut1 < nums1.size() ? nums1[cut1] : INT_MAX;

            int l2 = cut2 > 0 ? nums2[cut2 - 1] : INT_MIN;
            int r2 = cut2 < nums2.size() ? nums2[cut2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 != 0)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > l2)   // cut is to the left
                r = cut1 - 1;
            else                // cut is to the right
                l = cut1 + 1;
        }
        return -1;
    }
};
