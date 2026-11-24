class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord))
            return 0;
        
        unordered_map<string, vector<string>> wordsByPattern;
        for (string& w : wordList)
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                wordsByPattern[pattern].push_back(w);
            }

        int steps = 1;
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int breadth = q.size();
            while (breadth--) {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return steps;
                for (size_t i=0; i<word.size(); i++) {
                    string pattern{word};
                    pattern[i] = '+';
                    for (string& neighbor : wordsByPattern[pattern])
                        if (!visited.contains(neighbor)) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                }
            }
            steps++;
        }
        return 0;
    }
};