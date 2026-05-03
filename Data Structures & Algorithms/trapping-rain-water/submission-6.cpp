
#include <ranges>
class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>> biggest(height.size());
        int biggest_l = 0;
        int biggest_r = height.size() - 1;
        for (int i=0; i<height.size(); i++) {
            if (height[biggest_l] <= height[i])
                biggest_l = i;
            biggest[i].first = biggest_l;

            int j = height.size() - 1 - i;
            if (height[j] >= height[biggest_r])
                biggest_r = j;
            biggest[j].second = biggest_r;
        }
        
        int total_area = 0;
        for (auto [i, bigs] : biggest | views::enumerate) {
            auto [l, r] = bigs;
            total_area += max(0, min(height[l], height[r]) - height[i]);
        }
        return total_area;
    }
};
