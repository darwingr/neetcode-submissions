// Freq maps, track overlap count and shortest
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        
        unordered_map<char, int> t_freqs;
        for (char c : t)
            t_freqs[c]++;

        unordered_map<char, int> s_freqs;
        int overlap = 0;
        string shortest = "";
        int l = 0;
        for (int r = 0; r<s.size(); r++) {
            char sr = s[r];
            s_freqs[sr]++;
            if (t_freqs.contains(sr) && s_freqs[sr] <= t_freqs[sr])
                overlap++;

            while (l<=r && overlap == t.size()) {
                if (r-l+1 < shortest.size() || shortest.empty())
                    shortest = s.substr(l, r-l+1);
                
                char sl = s[l];
                if (t_freqs.contains(sl) && s_freqs[sl] <= t_freqs[sl])
                    overlap--;
                s_freqs[sl]--;
                l++;
            }
        }
        return shortest;
    }
};
