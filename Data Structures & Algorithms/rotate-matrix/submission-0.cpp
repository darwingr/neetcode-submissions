//  O(N^2)
//  O(N^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ranges::reverse(matrix);

        for (int i=0; i<matrix.size(); i++)
            for (int j=1+i; j<matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
