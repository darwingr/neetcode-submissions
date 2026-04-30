// DFS & TrieNodes
struct TrieNode {
    unordered_map<char, TrieNode*> chars;
    bool word_end = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        auto* node = root;
        for (char c : word) {
            if (!node->chars.contains(c))
                node->chars[c] = new TrieNode;
            node = node->chars[c];
        }
        node->word_end = true;
    }
    
    bool search(string word) {
        return subsearch(word, root, 0);
    }
    bool subsearch(string word, TrieNode* node, size_t start = 0) {
        for (int i=start; i<word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!node->chars.contains(c))
                    return false;
                node = node->chars[c];
            } else {
                if (i > 1 && word.substr(i-2, 2) == "..")
                    return false;
                for (auto [_, child] : node->chars)
                    if (subsearch(word, child, i+1))
                        return true;
                return false;

            }
            
        }
        return node->word_end;
    }
};
