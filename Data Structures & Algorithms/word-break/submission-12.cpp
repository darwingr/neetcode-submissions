// DP: bottom up
//  O([S] * [D] * [max(D)])
//  O([S])
class Solution {
public:
    // for each size of s, find the word that fits at front
    // Save if possible for each
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> reachesEnd(s.size() + 1, false);
        reachesEnd.back() = true;
        
        for (int i=s.size()-1; i>=0; i--) {
            for (auto& word : wordDict) {
                if (word == s.substr(i, word.size()))
                    reachesEnd[i] = reachesEnd[i + word.size()];

                if (reachesEnd[i])
                    break;
            }
        }

        return reachesEnd.front();
    }
};
