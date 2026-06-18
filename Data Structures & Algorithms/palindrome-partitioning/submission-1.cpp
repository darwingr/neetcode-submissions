// Backtracking: string view to simplify
//      could be faster to cache s[i]==s[j] lookup but loses string_view benefit
//  O(N x 2^N)
//  O(N)
class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string_view> subs;
        string_view sv{s};
        dfs(s, subs);
        return res;
    }

    void dfs(string_view sv, vector<string_view>& subs) {
        if (sv.empty()) {
            res.push_back(vector<string>{subs.begin(), subs.end()});
            return;
        }

        // find a pal
        for (int size=1; size<=sv.size(); size++) {
            for (size_t i=0, j=size-1; i<=size/2; i++, j--) {
                if (sv[i] != sv[j])
                    break;
                else if (j-i<=1) {
                    subs.push_back(sv.substr(0, size));
                    dfs(sv.substr(size), subs);
                    subs.pop_back();
                }
            }
        }
    }
};