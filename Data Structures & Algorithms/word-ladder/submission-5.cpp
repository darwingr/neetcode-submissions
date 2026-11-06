class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (!ranges::contains(wordList, endWord))
            return 0;
        
        // build patterns
        unordered_map<string, vector<string>> wordMatch;
        for (const string& w : wordList)
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                wordMatch[pattern].push_back(w);
            }
        
        // bfs
        int steps = 1;
        unordered_set<string_view> visited{beginWord};
        queue<string_view> q;
        q.push(beginWord);
        while (!q.empty()) {
            size_t breadth = q.size();
            while (breadth--) {
                auto w = q.front();
                q.pop();

                if (w == endWord)
                    return steps;

                for (size_t i=0; i<w.size(); i++) {
                    string pattern{w};
                    pattern[i] = '+';
                    for (string& nei : wordMatch[pattern])
                        if (!visited.contains(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                }

            }
            steps++;
        }
        
        return 0;
    }
};
