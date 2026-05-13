// Bin Search
//  O(log(min(N, M)))
//  O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1 is smaller
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        
        // Virtual L & R
        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = half - m1;

            // L&R values with range checks
            int l1 = m1 > 0 ? nums1[m1 - 1] : INT_MIN;
            int r1 = m1 < nums1.size() ? nums1[m1] : INT_MAX;
            int l2 = m2 > 0 ? nums2[m2 - 1] : INT_MIN;
            int r2 = m2 < nums2.size() ? nums2[m2] : INT_MAX;
            
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 != 0)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                r = m1 - 1;
            else
                l = m1 + 1;

        }
        return -1;
    }
};
