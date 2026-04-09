// GRAPH: DFS - overlapping visited lists
//  O(m x n) - Linear!
//  O(m x n)
class Solution {
    int rows;
    int cols;
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 1. Find the highest point reached from each coastline.
        // 2. See where there's overlap

        rows = heights.size();
        cols = heights[0].size();

        // Pacific
        vector<vector<bool>> pac_source(rows, vector<bool>(cols));
        // left edge
        for (int i=0; i<rows; i++)
            findPeak(i, 0, pac_source, heights);
        // top edge
        for (int j=0; j<cols; j++)
            findPeak(0, j, pac_source, heights);

        // Atlantic
        vector<vector<bool>> atl_source(rows, vector<bool>(cols));
        // right edge
        for (int i=0; i<rows; i++)
            findPeak(i, cols-1, atl_source, heights);
        // bottom edge
        for (int j=0; j<cols; j++)
            findPeak(rows-1, j, atl_source, heights);
        

        vector<vector<int>> sources;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                if (pac_source[i][j] && atl_source[i][j])
                    sources.push_back({i, j});
        
        return sources;
    }

    void findPeak(int i, int j, vector<vector<bool>>& visited, const vector<vector<int>>& heights) {
        visited[i][j] = true;
        int height = heights[i][j];
        // look down
        if (i+1 < rows
                && !visited[i+1][j]
                && heights[i+1][j] >= height)
            findPeak(i+1, j, visited, heights);
        // look right
        if (j+1 < cols
                && !visited[i][j+1]
                && heights[i][j+1] >= height)
            findPeak(i, j+1, visited, heights);
        // look up
        if (i-1 >= 0
                && !visited[i-1][j]
                && heights[i-1][j] >= height)
            findPeak(i-1, j, visited, heights);
        // look left
        if (j-1 >= 0
                && !visited[i][j-1]
                && heights[i][j-1] >= height)
            findPeak(i, j-1, visited, heights);
    }
};
