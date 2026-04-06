// DP - space optimal
//  O(N)
//  O(1)
class Solution {
public:
/*

*/
    int numDecodings(string s) {
        int ways = s.back() != '0';
        int ways1 = ways;
        int ways2 = 1;
    
        for (int i=s.size()-2; i>=0; i--) {
            // 0X...
            if (s[i] == '0')
                ways = 0;

            // 1-9X...
            if (s[i] != '0')
                ways = ways1;
            
            // [10-26]...
            if (between_10_26(s[i], s[i+1]))
                ways += ways2;
            
            ways2 = ways1;
            ways1 = ways;
        }
        return ways;
    }

    bool between_10_26(char d1, char d2) const {
        return d1 == '1'
            || d1 == '2' && d2 - '0' < 7;
    }
};
