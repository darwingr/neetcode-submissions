// DP: bottom up. Memo min at i
//  O(N)
//  O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mins(cost.size());
        //mins.back() = cost.back();
        mins[mins.size()-1] = cost[cost.size()-1];
        mins[mins.size()-2] = cost[cost.size()-2];

        // skip last two
        for (int i=mins.size()-1-2; i>=0; i--)
            mins[i] = cost[i] + min(mins[i+1], mins[i+2]);

        return min(mins[0], mins[1]);
    }
};
