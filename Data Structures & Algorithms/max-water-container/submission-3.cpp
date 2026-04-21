// 2 pointers
//  O(N)
//  O(1)
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int best = 0;

        while (l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            best = max(best, area);
            if (heights[l] < heights[r])
                l++;
            else if (heights[l] > heights[r])
                r--;
            else {//if (r - heights.size() )
                l++;
                r--;
            }
        }
        return best;
    }
};
