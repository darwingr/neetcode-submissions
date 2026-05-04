// 
//  O(log N)
//  O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t l = 0;
        size_t r = matrix.size() - 1;
        // find row
        while (l<=r && matrix[l].front() <= target && target <= matrix[r].back()) {
            size_t mid = l + (r - l) / 2;
            if (target < matrix[mid].front())
                r = mid - 1;
            else if (target > matrix[mid].back())
                l = mid + 1;
            // find col
            else {
                size_t i = 0;
                size_t j = matrix[mid].size() - 1;
                while (i<=j) {
                    if (target < matrix[mid][i] || matrix[mid][j] < target)
                        return false;
                    size_t m = i + (j - i) / 2;
                    if (matrix[mid][m] == target)
                        return true;
                    else if (target < matrix[mid][m])
                        j = m - 1;
                    else
                        i = m + 1;
                }
            }
        }
        return false;
    }
};
