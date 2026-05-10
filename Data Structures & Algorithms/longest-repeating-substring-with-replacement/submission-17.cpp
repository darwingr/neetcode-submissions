// Freq map, track max freq & longest
//  O(N)
//  O(uniqs)
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int maxf = 0;
        int longest = 0;
        
        int l = 0;
        for (int r=0; r<s.size(); r++) {
            freqs[s[r]]++;
            maxf = max(maxf, freqs[s[r]]);

            auto dist = [&](){return r-l+1;};
            // is this repeating-ish?
            while (dist() > maxf + k) {
                freqs[s[l]]--;
                l++;
            }
            longest = max(longest, dist());
        }
        return longest;
    }
};
