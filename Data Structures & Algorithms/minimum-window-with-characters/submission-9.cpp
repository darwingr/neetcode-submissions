// Slide Window:
//      right until overlap
//      either use size 128 or do `- 'A'` for char_freqs
//  O(s + t)
//  O(uniq(s) + uniq(t))
class Solution {
public:
    string minWindow(string_view s, string t) {
        array<int, 128> t_freqs{};
        for (char c : t)
            t_freqs[c]++;

        array<int, 128> s_freqs{};
        int overlap = 0;
        int r = 0;
        do {
            if (r >= s.size())
                return "";
            size_t cr = s[r];
            s_freqs[cr]++;
            if (s_freqs[cr] <= t_freqs[cr])
                overlap++;
            r++;
        } while (overlap < t.size());
        r--;
        string_view min_ss = s.substr(0, r+1);
        
        int l = 0;
        while (r < s.size()) {
            // within an overlap
            if (overlap >= t.size()) {
                if (min_ss.size() > r - l + 1)
                    min_ss = s.substr(l, r - l + 1);

                size_t cl = s[l];
                s_freqs[cl]--;
                if (s_freqs[cl] < t_freqs[cl])
                    overlap--;
                l++;
            } else{
                if (r+1 == s.size())
                    break;
                r++;
                size_t cr = s[r];
                s_freqs[cr]++;
                if (s_freqs[cr] <= t_freqs[cr])
                    overlap++;
            }
        }

        return string(min_ss);
    }
};
