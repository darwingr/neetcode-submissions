// Sliding window (for): freq map, track maxf & longest
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freqs;
        int longest = 0;
        int maxf = 0;

        int l = 0;
        for (int r = 0; r<s.size(); r++) {
            freqs[s[r]]++;
            maxf = max(maxf, freqs[s[r]]);

            while (maxf + k < r - l + 1) {
                freqs[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
