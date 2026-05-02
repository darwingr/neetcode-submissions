// Sliding window: freq maps, count overlap, track min
//      inc l if overlapping, inc r if not
//  O(s)
//  O(uniq(s, t))
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freqs;
        for (char c : t)
            t_freqs[c]++;

        int overlap = 0;

        unordered_map<char,int> s_freqs;
        string_view sv{s};
        string_view minimum;
        int l = 0;
        for (int r=0; r<sv.size(); r++) {
            s_freqs[s[r]]++;

            if (s_freqs[s[r]] <= t_freqs[s[r]])
                overlap++;

            while (overlap >= t.size()) {
                if (r - l + 1 < minimum.size() || minimum.empty())
                    minimum = sv.substr(l, r - l + 1);
                
                s_freqs[s[l]]--;
                if (s_freqs[s[l]] < t_freqs[s[l]])
                    overlap--;
                l++;
            }
        }
        return string{minimum};
    }
};
