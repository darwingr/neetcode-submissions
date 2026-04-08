// DYnamic Programming
class Solution {
public:
    int numDecodings(string s) {
        int ways;
        int ways1 = s.back() == '0' ? 0 : 1;
        int ways2 = 1;

        for (int i=s.size()-2; i>=0; i--) {
            if (s[i] == '0')
                ways = 0;

            if (s[i] != '0')
                ways = ways1;

            if (between_10_26(s[i], s[i+1]))
                ways += ways2;

            ways2 = ways1;
            ways1 = ways;
        }
        return ways1;
    }

    bool between_10_26(char d1, char d2) const {
        return d1 == '1'
            || d1 == '2' && d2 - '0' < 7;
    }
};
