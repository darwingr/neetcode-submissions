// 2D-grid + 1 for init
//      for each combo do 1+diagonal if chars match,
//      otherwise get directly below or to the right
//  O(t1 * t2)
//  O(t1 * t2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mcounts(text1.size()+1,
                                    vector<int>(text2.size()+1));
        
        for (int t1=text1.size()-1; t1>=0; t1--) {
            for (int t2=text2.size()-1; t2>=0; t2--) {
                if (text1[t1] == text2[t2])
                    mcounts[t1][t2] = 1 + mcounts[t1+1][t2+1];
                else
                    mcounts[t1][t2] = max(mcounts[t1+1][t2],
                                          mcounts[t1][t2+1]);
            }
        }
        return mcounts.front().front();
    }
};
