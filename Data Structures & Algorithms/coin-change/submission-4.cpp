// O(C * A)
// O(A)
//      A - amount
//      C - number of coin denominations
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // the fewest num of coins for each sub-amount
        vector<int> amts(amount + 1, INT_MAX);
        amts[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int coin : coins) {
                if (i-coin >= 0 && amts[i - coin] < INT_MAX)
                    amts[i] = min(amts[i], amts[i - coin] + 1);
            }
        }

        return amts[amount] == INT_MAX
            ? -1
            : amts[amount];
    }
};
