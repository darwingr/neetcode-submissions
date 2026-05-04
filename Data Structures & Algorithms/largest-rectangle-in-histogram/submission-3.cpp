#include <ranges>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largest = 0;
        stack<int> stack;

        for (int i=0; i <= heights.size(); i++) {
            while (!stack.empty()
                && (i == heights.size()
                ||  heights[stack.top()] >= heights[i])
            ) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                largest = max(largest, width * height);
            }
            stack.push(i);
        }
        return largest;
    }
};
