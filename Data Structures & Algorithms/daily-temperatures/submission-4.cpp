// Stack indices, diff curr with stack top if top < current
//  O(N)
//  O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> index_stack;
        vector<int> result(temperatures.size());
        for (int i=0; i<temperatures.size(); i++) {
            while (!index_stack.empty()
                && temperatures[index_stack.top()] < temperatures[i]
            ) {
                int j = index_stack.top();
                index_stack.pop();
                result[j] = i - j;
            }
            index_stack.push(i);
        }
        return result;
    }
};
