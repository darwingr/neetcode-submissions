// DP bottom up: fit another
//  O([S] * [D] * [max(D)])
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> fits_substring(s.size() + 1);
        fits_substring.back() = true;

        for (int i=s.size()-1; i >= 0; i--) {
            for (string& word : wordDict) {
                if (word == s.substr(i, word.size()))
                    fits_substring[i] = fits_substring[i + word.size()];

                if (fits_substring[i])
                    break;
            }
        }

        return fits_substring.front();
    }
};
