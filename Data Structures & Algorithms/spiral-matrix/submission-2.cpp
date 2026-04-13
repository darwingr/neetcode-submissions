// SHRINKING BOUNDARIES
//  O(m * n) - linear
//  O(1) - algo only space
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        //res.reserve(matrix.size() * matrix[0].size());
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();

        while (left < right && top < bottom) {
            for (int j=left; j<right; j++)
                res.push_back(matrix[top][j]);
            top++;

            for (int i=top; i<bottom; i++)
                res.push_back(matrix[i][right-1]);
            right--;

            if (left >= right || top >= bottom)
                break;

            for (int j=right-1; j>=left; j--)
                res.push_back(matrix[bottom-1][j]);
            bottom--;

            for (int i=bottom-1; i>=top; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};
