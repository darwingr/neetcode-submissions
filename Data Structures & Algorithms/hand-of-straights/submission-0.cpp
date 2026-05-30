// Greedy:
//  O(N log N)
//  O(N)
#include <ranges>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int,int> freqs;
        for (int n : hand)
            freqs[n]++;

        while (!freqs.empty()) {
            int i = 0;
            for (auto [val, freq] : freqs) {
                if (i % groupSize != groupSize-1 && !freqs.contains(val+1))
                    return false;
                freqs[val]--;
                if (freqs[val] == 0)
                    freqs.erase(val);
                i++;
                if (i == groupSize)
                    break;
            }
        }
        return true;
    }
};
