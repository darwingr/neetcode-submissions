// 2-pass, set body, then 1st col, then 1st row
//  O(M * N)
//  O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // set hints
        bool zero_row0 = false;
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i == 0)
                        zero_row0 = true;
                    else
                        matrix[i][0] = 0; 
                }
        
        // set body
        for (int i=1; i<matrix.size(); i++)
            for (int j=1; j<matrix[0].size(); j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
        
        // set 1st col
        if (matrix[0][0] == 0)
            for (int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;

        // set 1st row
        if (zero_row0)
            matrix[0] = vector<int>(matrix[0].size());
    }
};
