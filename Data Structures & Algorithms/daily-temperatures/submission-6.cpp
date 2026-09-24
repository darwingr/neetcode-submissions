class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> mstack; // index of last biggest
        for (int i=0; i<temperatures.size(); i++) {
            int t = temperatures[i];
            while (!mstack.empty()
                && t > temperatures[mstack.top()])
            {
                int j = mstack.top();
                mstack.pop();
                res[j] = i - j;
            }
            mstack.push(i);
        }
        return res;
    }
};
