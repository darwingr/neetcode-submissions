class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> uniqs;
        int l = 0;
        int maxc = 0;

        for (int r=0; r<s.size(); r++) {
            char c = s[r];
            if (uniqs.contains(c))
                l = max(uniqs[c] + 1, l);
            uniqs[c] = r;
            maxc = max(maxc, r - l + 1);
        }
        return maxc;
    }
};
