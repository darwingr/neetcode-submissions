class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string tok : tokens) {
            if (tok.back() >= '0' && tok.back() <= '9')
                stk.push(stoi(tok));
            else {
                int b = stk.top();
                stk.pop();
                if (tok == "+")
                    stk.top() += b;
                else if (tok == "-")
                    stk.top() -= b;
                else if (tok == "*")
                    stk.top() *= b;
                else if (tok == "/")
                    stk.top() /= b;
            }
        }
        return stk.top();
    }
};
