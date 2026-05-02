// Save vals & results in stack until you hit an op
//  O(N)
//  O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> val_stack;
        for (string& tok : tokens) {
            if (isdigit(tok.back()))
                val_stack.push(stoi(tok));
            else {
                int b = val_stack.top();
                val_stack.pop();
                int a = val_stack.top();
                val_stack.pop();

                int result;
                if (tok == "+")
                    result = a + b;
                else if (tok == "-")
                    result = a - b;
                else if (tok == "*")
                    result = a * b;
                else if (tok == "/") {

                    result = a / b;
                }

                val_stack.push(result);
            }
        }
        return val_stack.top();
    }
};
