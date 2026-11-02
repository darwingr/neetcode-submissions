class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if (endWord.empty()
        || ranges::find(wordList, endWord) == wordList.end())
            return 0;

        unordered_map<string, vector<string>> wordsByPattern;
        wordList.push_back(beginWord);
        for (const string& word : wordList)
            for (int j=0; j<word.size(); j++) {
                string pattern{word};
                pattern[j] = '+';
                wordsByPattern[pattern].push_back(word);
            }

        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            size_t size = q.size();
            for (size_t i = 0; i<size; i++) {
                string word{q.front()};
                q.pop();
                if (word == endWord)
                    return res;
                
                for (size_t j=0; j<word.size(); j++) {
                    string pattern = word;
                    pattern[j] = '+';

                    for (string& nei :wordsByPattern[pattern])
                        if (!visited.contains(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                }
            }
            res++;
        }
        return 0;
    }
};
