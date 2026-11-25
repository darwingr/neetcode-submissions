class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        queue<int> count_q;
        count_q.push(0);
        vector<bool> seen(amount + 1, false); // amount == count for 1C coins
        seen[0] = true;;
        int count = 0;

        while (!count_q.empty()) {
            count++;
            size_t breadth = count_q.size();
            for (size_t i=0; i<breadth; i++) {
                int cur = count_q.front();
                count_q.pop();
                for (int coin : coins) {
                    if (coin > amount - cur)
                        continue;
                    int next = cur + coin;
                    if (next == amount)
                        return count;
                    if (seen[next])
                        continue;
                    seen[next] = true;
                    count_q.push(next);
                }
            }
        }

        return -1;
    }
};
