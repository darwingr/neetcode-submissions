// Backtracking: track open/closed & current string ref
//  O(4^n / sqrt(n))
//      O(2^(2xn))
//      div by sqrt since not all paths are explored
//  O(N) - longest built string
class Solution {
    vector<string> res;
public:
    /*
    1 ()
    2 ()(), (())
    3 ()()(), (()()), (())(), ()(()) ((()))
    */
    vector<string> generateParenthesis(int n) {
        res.clear();
        string s = "";
        res.reserve(2*n);
        dfs(n, s);
        return res;
    }

    void dfs(const int n, string& s, const int open = 0, const int close = 0) {
        if (close == n) {
            res.push_back(s);
            return;
        }

        if (open + close < n) {
            s.push_back('(');
            dfs(n, s, open + 1, close);
            s.pop_back();
        }
        if (open > 0) {
            s.push_back(')');
            dfs(n, s, open - 1, close + 1);
            s.pop_back();
        }
    }
};
