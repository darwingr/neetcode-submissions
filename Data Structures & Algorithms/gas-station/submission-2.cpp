// Greedy: track last best price & running cost
//  - find the cheapest gas
//  At each station
//      - fill up enough to get to n, if less fill up there, else assume filled up at the last best
// DP: bottom-up?
//  O(N)
//  O(1)
#include <ranges>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        for (auto [g, c] : views::zip(gas, cost)) {
            // get all the gas at each pump
            tank += g;
            tank -= c;
        }
        if (tank < 0)
            return -1;

        int start = 0;
        tank = 0;
        for (int i=0; i<gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
