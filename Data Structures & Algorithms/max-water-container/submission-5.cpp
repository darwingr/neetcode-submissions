// 2-Pointer: Out to in
//  O(N)
//  O(1)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;
        while (l < r) {
            int height = min(heights[l], heights[r]);
            int dist = r - l;
            max_area = max(max_area, height * dist);
            if (heights[l] > heights[r])
                r--;
            else
                l++;
        }
        return max_area;
    }
};
