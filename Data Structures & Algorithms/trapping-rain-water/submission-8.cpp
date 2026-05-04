// 2-Pass: 2-Pointer biggest to L&R for each i
//         calc area for each col, then sum
//  O(N)
//  O(N)
#include <ranges>
class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> biggest(height.size());
        int biggest_l = 0;
        int biggest_r = height.size()-1;
        for (int i=0, j=height.size()-1; i<height.size(); i++, j--) {
            if (height[biggest_l] <= height[i])
                biggest_l = i;
            biggest[i].first = biggest_l;

            if (height[j] >= height[biggest_r])
                biggest_r = j;
            biggest[j].second = biggest_r;
        }

        int sum = 0;
        for (auto [i, big] : biggest | views::enumerate) {
            auto [l, r] = big;
            int water_height = min(height[l], height[r]);
            sum += max(0, water_height - height[i]);
        }
        return sum;
    }
};
