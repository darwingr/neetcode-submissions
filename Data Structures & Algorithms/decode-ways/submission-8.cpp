// DP - space optimal
//  O(N)
//  O(1)
class Solution {
public:
    int numDecodings(string s) {
        int ways1 = s.back() != '0';
        int ways2 = 1;

        for (int i=s.size()-2; i>=0; i--) {
            int ways0 = 0;

            if (s[i] != '0') {
                ways0 = ways1;
                int num = stoi(s.substr(i, 2));
                if (num < 27)
                    ways0 += ways2;
            }
            ways2 = ways1;
            ways1 = ways0;
        }
        return ways1;
    }

    bool gt6(char n) {
        int z = n - '0';
        return z > 6;
    }
};
