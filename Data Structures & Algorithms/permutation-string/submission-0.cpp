// Compare freq maps, slide the window
//  O(s1 + s2)
//  O(uniq s1 + uniq s2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_freqs;
        for (char c : s1)
            s1_freqs[c]++;
        unordered_map<char, int> freqs;
        int matches = 0;
        
        int l = 0;
        int r = 0;
        while (r < s2.size()) {
            char sr = s2[r];
            if (!s1_freqs.contains(sr) || s1_freqs[sr] == 0
            ) {
                r++;
                l = r;
                freqs.clear();
                matches = 0;
                continue;
            }

            freqs[sr]++;
            if (s1_freqs[sr] == freqs[sr]) {
                matches++;
                if (matches == s1_freqs.size())
                    return true;
            }
            else while (s1_freqs[sr] < freqs[sr]) {
                char sl = s2[l];
                if (freqs[sl] == s1_freqs[sl])
                    matches--;
                freqs[sl]--;
                l++;
            }
            r++;
        }
        return false;
    }
};
