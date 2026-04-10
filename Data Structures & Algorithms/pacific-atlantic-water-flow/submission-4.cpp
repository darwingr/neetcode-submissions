// DFS - find downlands, return overlap
class Solution {
    int rows;
    int cols;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pac_sources(rows, vector<bool>(cols));
        vector<vector<bool>> atl_sources(rows, vector<bool>(cols));
        // top and bottom
        for (int j=0; j<cols; j++) {
            climbFrom(0,      j, pac_sources, heights);
            climbFrom(rows-1, j, atl_sources, heights);
        }
        // left and right
        for (int i=0; i<rows; i++) {
            climbFrom(i, 0,      pac_sources, heights);
            climbFrom(i, cols-1, atl_sources, heights);
        }

        // find overlap
        vector<vector<int>> sources;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                if (atl_sources[i][j] && pac_sources[i][j])
                    sources.push_back({i, j});
        return sources;
    }

    void climbFrom(int row, int col, vector<vector<bool>>& visited, const vector<vector<int>>& heights) {
        visited[row][col] = true;
        int height = heights[row][col];
        // right
        if (row+1 < rows
                && !visited[row+1][col]
                && height <= heights[row+1][col])
            climbFrom(row+1, col, visited, heights);
        // left
        if (row-1 >= 0
                && !visited[row-1][col]
                && height <= heights[row-1][col])
            climbFrom(row-1, col, visited, heights);
        // down
        if (col+1 < cols
                && !visited[row][col+1]
                && height <= heights[row][col+1])
            climbFrom(row, col+1, visited, heights);
        // up
        if (col-1 >= 0
                && !visited[row][col-1]
                && height <= heights[row][col-1])
            climbFrom(row, col-1, visited, heights);
    }
};
