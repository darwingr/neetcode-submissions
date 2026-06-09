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
