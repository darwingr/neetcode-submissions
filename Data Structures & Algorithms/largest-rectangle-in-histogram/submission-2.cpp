class Solution {
public:
    // STACK
    //
    // 
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        // stack tallest height on top: index & height
        //  pop when decreasing height
        //  push
        auto talls = stack<pair<int, int>>();

        for (int i=0; i<heights.size(); i++) {
            int start = i;
            int i_height = heights.at(i);
            while (!talls.empty() && talls.top().second > i_height) {
                auto [top_idx, top_height] = talls.top();
                // first see what area we could have got
                int area = (i - top_idx) * top_height;
                if (area > max_area)
                    max_area = area;
                start = top_idx;
                talls.pop();
            }
            talls.push({ start, i_height });
        }
        while (!talls.empty()) {
            auto [top_idx, top_height] = talls.top();
            int area = (heights.size() - top_idx) * top_height;
            max_area = max(
                max_area,
                area
            );
            talls.pop();
        }
        return max_area;
    }
};
