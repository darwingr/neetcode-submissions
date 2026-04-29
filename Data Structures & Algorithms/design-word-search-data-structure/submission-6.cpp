// Use Trie Node
struct TrieNode {
    array<TrieNode*, 26> char_map = array<TrieNode*, 26>();
    bool word_end = false;
};

class WordDictionary {
    TrieNode* root;
public:
    // O(1) / O(1)
    WordDictionary() {
        root = new TrieNode;
    }
    
    // T O(word size)
    // S O(max(dict, word))
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->char_map[c - 'a'])
                node->char_map[c - 'a'] = new TrieNode;
            node = node->char_map[c - 'a'];
        }
        node->word_end = true;
    }
    
    // T O(word size)
    // S O(dict)
    bool search(string word) {
        return search(word, root, 0);
    }
private:
    bool search(string_view word, TrieNode* node, int dot_count) {
        if (word.empty())
            return node->word_end;
        
        char c = word.front();
        if (c == '.') {
            if (dot_count >= 2)
                return false;
            dot_count++;

            // consider all
            for (TrieNode* tn : node->char_map)
                if (tn && search(word.substr(1), tn, dot_count))
                    return true;
            return false;
        }
        else
            dot_count = 0;
            
        // if any possibles exist
        return node->char_map[c - 'a']
            && search(word.substr(1), node->char_map[c - 'a'], dot_count);
    }
};
