// BUCKET SORT
//  O(N + MAX_VAL)
//  O(MAX_VAL)
//  Thecnically both are O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        array<int,101> stones_by_weight;
        int count = stones.size();
        for (int s : stones)
            stones_by_weight[s]++;
        
        int carry = 0;
        for (int w=100; w>0; w--) {
            while (stones_by_weight[w] >= 1) {
                if (carry) {
                    int diff = abs(carry - w);
                    stones_by_weight[w]--;
                    carry = 0;
                    if (diff <= w)
                        stones_by_weight[diff]++;
                    else
                        carry = diff;
                }
                else if (stones_by_weight[w] > 1) {
                    int half = stones_by_weight[w] / 2;
                    stones_by_weight[w] -= half * 2;
                }
                else if (stones_by_weight[w] == 1) {
                    stones_by_weight[w]--;
                    carry = w;
                }
            }
        }
        return max(carry, 0);
    }
};
