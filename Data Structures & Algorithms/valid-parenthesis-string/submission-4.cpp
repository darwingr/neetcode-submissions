// Greedy: 2-stacks paren & star indices
//  O(N)
//  O(N)
class Solution {
public:
    bool checkValidString(string s) {
        stack<size_t> parens;
        stack<size_t> stars;

        for (size_t i=0; i<s.size(); i++) {
            if (s[i] == '(')
                parens.push(i);

            else if (s[i] == '*')
                stars.push(i);

            else if (s[i] == ')') {
                if (!parens.empty()) {
                    size_t left = parens.top();
                    parens.pop();
                }
                else if (!stars.empty())
                    stars.pop();
                else
                    return false;
            }
        }
        while (!stars.empty() &&
               !parens.empty() &&
                parens.top() < stars.top()
        ) {
            parens.pop();
            stars.pop();
        }

        return parens.empty();
    }
};
