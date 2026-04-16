// Shrinking Boundaries
//  O(M * N)
//  O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int left = 0;
        
        int cells = matrix.size() * matrix[0].size();
        vector<int> output;
        output.reserve(cells);
        while (cells) {
            // top
            for (int j=left; j<=right; j++, cells--)
                output.push_back(matrix[top][j]);
            top++;
            // right
            for (int i=top; i<=bottom; i++, cells--)
                output.push_back(matrix[i][right]);
            right--;

            if (!cells) break;

            // bottom
            for (int j=right; j>=left; j--, cells--)
                output.push_back(matrix[bottom][j]);
            bottom--;
            // left
            for (int i=bottom; i>=top; i--, cells--)
                output.push_back(matrix[i][left]);
            left++;
        }
        return output;
    }
};
