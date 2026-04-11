// Bottom up
//  O(m * n)
//  O(m * n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lengths(text1.size() + 1,
                                    vector<int>(text2.size() + 1));

        for (int i = text1.size()-1; i>=0; i--) {
            for (int j=text2.size()-1; j>=0; j--) {
                if (text1[i] == text2[j])
                    lengths[i][j] = 1 + lengths[i+1][j+1];
                else
                    lengths[i][j] = max(lengths[i][j+1],
                                        lengths[i+1][j]);
            }
        }
        return lengths[0][0];
    }
};
