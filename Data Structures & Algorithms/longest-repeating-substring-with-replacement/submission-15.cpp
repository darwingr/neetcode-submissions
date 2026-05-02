// sliding window: freq map, track longest & maxf
//  O(s)
//  O(uniqs)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int longest = 0;
        int maxfreq = 0;

        int l=0;
        for (int r=0; r<s.size(); r++) {
            freqs[s[r]]++;
            maxfreq = max(maxfreq, freqs[s[r]]);

            while (maxfreq + k < (r - l + 1)) {
                freqs[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};
