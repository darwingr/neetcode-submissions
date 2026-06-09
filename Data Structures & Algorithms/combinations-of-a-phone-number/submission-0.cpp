// Backtracking: 
//  O(2^(3xN))
//  O(N)
class Solution {
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        string s;
        dfs(digits, s);
        return res;
    }

    void dfs(const string& digits, string& s, size_t i=0) {
        if (i==digits.size() && !s.empty()) {
            res.push_back(s);
            return;
        }

        auto lam = [&](string subs) {
            for (char c : subs) {
                s.push_back(c);
                dfs(digits, s, i+1);
                s.pop_back();
            }
        };

        switch(digits[i]) {
            case '2':
                lam("abc");
                break;
            case '3':
                lam("def");
                break;
            case '4':
                lam("ghi");
                break;
            case '5':
                lam("jkl");
                break;
            case '6':
                lam("mno");
                break;
            case '7':
                lam("pqrs");
                break;
            case '8':
                lam("tuv");
                break;
            case '9':
                lam("wxyz");
                break;
        }
    }
};
