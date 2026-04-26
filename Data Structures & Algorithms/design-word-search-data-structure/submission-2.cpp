using LowercaseGlob = std::string;
using LowercaseString = std::string;

class TrieNode {
public:
    unordered_map<char, TrieNode*> char_map;
    bool word_end = false;

    bool search(LowercaseGlob glob) {
        if (word_end && glob.empty())
            return true;

        char c = glob.front();
        if (c == '.')
            for (auto [_, t] : char_map)
                if (t->search(glob.substr(1)))
                    return true;
        
        if (!char_map.count(c))
            return false;
        else
            return char_map[c]->search(glob.substr(1));
    }
};

class WordDictionary {
public:
    WordDictionary() : trie_root(new TrieNode()) {}
    
    void addWord(LowercaseString word) {
        auto t = trie_root;
        for (auto c : word) {
            if (!t->char_map.count(c)) {
                t->char_map[c] = new TrieNode;
            }
            t = t->char_map[c];
        }
        t->word_end = true;
    }
    
    bool search(LowercaseGlob glob) {
        return trie_root->search(glob);
    }
private:
    TrieNode* trie_root;
};