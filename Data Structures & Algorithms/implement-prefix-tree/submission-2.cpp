// TrieNodes: bool word_end & char map
struct TrieNode {
    array<TrieNode*, 26> char_map = array<TrieNode*, 26>();
    bool word_end = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode;
    }
    
    // O(N) / O(N)
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->char_map[c - 'a'])
                node->char_map[c - 'a'] = new TrieNode;
            node = node->char_map[c - 'a'];
        }
        node->word_end = true;
    }
    
    // O(N) / O(1)
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            node = node->char_map[c - 'a'];
            if (!node)
                return false;
        }
        return node->word_end;
    }
    
    // O(N) / O(1)
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            node = node->char_map[c - 'a'];
            if (!node)
                return false;
        }
        return true;
    }
};
