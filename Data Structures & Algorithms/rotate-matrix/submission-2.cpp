// Reverse & Transpose
//  O(N) - Linear, N^2 vs length of side
//  O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Reverse columns
        for (int j=0; j<matrix[0].size(); j++)
            for (int a=0, b=matrix.size()-1; a<b; a++, b--)
                swap(matrix[a][j], matrix[b][j]);
        
        // Transpose
        for (int i=0; i<matrix.size(); i++)
            for (int j=i+1; j<matrix[0].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};