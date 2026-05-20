class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heavies;
        for (int s : stones)
            heavies.push(s);

        while (heavies.size() > 1) {
            int x = heavies.top();
            heavies.pop();
            int y = heavies.top();
            heavies.pop();
            int diff = abs(x - y);
            if (diff > 0)
                heavies.push(diff);
            else if (heavies.empty())
                return 0;
        }
        return heavies.top();
    }
};
