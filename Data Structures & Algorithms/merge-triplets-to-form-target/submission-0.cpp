// Greedy:
//  O(N)
//  O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        size_t nearest = triplets.size();

        for (int i=0; i<triplets.size(); i++) {
            auto& trip = triplets[i];
            if (trip[0] > target[0] ||
                trip[1] > target[1] ||
                trip[2] > target[2]
            )
                continue;
            
            if (nearest != triplets.size())
                update(nearest, i, triplets);
            nearest = i;

            if (trip[0] == target[0] &&
                trip[1] == target[1] &&
                trip[2] == target[2]
            )
                return true;
        }
        return false;
    }

    void update(size_t i, size_t j, vector<vector<int>>& triplets) {
        if (i >= triplets.size() || j >= triplets.size()) return;
        triplets.at(j) = {
            max(triplets[i][0], triplets[j][0]),
            max(triplets[i][1], triplets[j][1]),
            max(triplets[i][2], triplets[j][2])
        };
    }
};
