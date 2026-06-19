// Greedy: track min/max possible unmatched left '('
//  O(N)
//  O(N)
class Solution {
public:
    bool checkValidString(string s) {
        int l_min = 0;
        int l_max = 0;
        
        for (char c : s) {
            switch (c) {
                case '(':
                    l_min++;
                    l_max++;
                    break;
                case ')':
                    l_min--;
                    l_max--;
                    break;
                case '*':
                    l_min--;
                    l_max++;
                    break;
            }

            if (l_max < 0)  return false;
            if (l_min < 0)  l_min = 0;
        }

        return l_min == 0;
    }
};
