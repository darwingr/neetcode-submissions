// Greedy: track min & max possible unmatched left parentheses
//  O(N)
//  O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int l_min = 0;
        int l_max = 0;

        for (char c : s) {
            if (c == '(') {
                l_min++;
                l_max++;
            }
            else if (c == ')') {
                l_min--;
                l_max--;
            }
            else { // if '*'
                l_min--;
                l_max++;
            }

            if (l_max < 0)
                return false;

            if (l_min < 0)
                l_min = 0;
        }
        return l_min == 0;
    }
};
