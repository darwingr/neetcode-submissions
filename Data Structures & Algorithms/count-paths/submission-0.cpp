// DP
//  O(m * n)
//  O(m * n)
class Solution {
    vector<vector<int>> paths_from;
public:
    int uniquePaths(int m, int n) {
        paths_from = vector(m, vector<int>(n));
        paths_from.back().back() = 1;
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (j+1 < n)
                    paths_from[i][j] += paths_from[i][j+1];
                if (i+1 < m)
                    paths_from[i][j] += paths_from[i+1][j];
            }
        }
        return paths_from.front().front();
    }
};
