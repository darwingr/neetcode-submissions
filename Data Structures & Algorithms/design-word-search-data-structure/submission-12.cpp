// DFS trie
//  O(string)
//  O(String + tree size)
class WordDictionary {
    unordered_map<char,WordDictionary*> trie_nodes;
    bool word_end = false;
public:
    WordDictionary() {}
    
    void addWord(string word) {
        if (!word.empty())
            addWord(string_view{word});
    }
    
    bool search(string word) {
        if (word.empty())
            return false;
        return search(string_view{word});
    }

private:
    void addWord(string_view word) {
        if (word.empty())
            word_end = true;
        else {
            if (!trie_nodes.contains(word.front()))
                trie_nodes[word.front()] = new WordDictionary();
            trie_nodes[word.front()]->addWord(word.substr(1));
        }
    }

    bool search(string_view word, int dots = 0) {
        if (word.empty())
            return word_end;
        else if (word.front() != '.' && !trie_nodes.contains(word.front()))
            return false;
        else if (word.front() == '.') {
            if (++dots > 2)
                return false;
            for (auto [_, node] : trie_nodes)
                if (node->search(word.substr(1), dots))
                    return true;
            return false;
        }
        else
            return trie_nodes[word.front()]->search(word.substr(1));
    }
};
