class CountSquares {
    unordered_map<
        int,
        unordered_map<int,int>
    > point_counts;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        point_counts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x1 = point[0];
        int y1 = point[1];

        for (auto& [y2, x1y2_count] : point_counts[x1]) {
            int side = y2 - y1;
            if (side == 0) continue;

            int x3 = x1 + side;
            int x4 = x1 - side;
            count += x1y2_count
                   * point_counts[x3][y1]
                   * point_counts[x3][y2];
            count += x1y2_count
                   * point_counts[x4][y1]
                   * point_counts[x4][y2];
        }
        return count;
    }
};
