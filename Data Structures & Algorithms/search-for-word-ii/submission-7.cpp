// Words to Trie, keep internal, dfs explore/mutate the board
//  T O(sum(words) + board * 4 * 3^(max word))
//  S O(sum(words))
struct TrieNode {
    unordered_map<char, TrieNode*> chars;
    bool word_end = false;

  public:
    void add(string w) {
        TrieNode* node = this;
        for (char c : w) {
            if (!node->chars.contains(c))
                node->chars[c] = new TrieNode;
            node = node->chars[c];
        }
        node->word_end = true;
    }
};

class Solution {
    int rows;
    int cols;
    vector<string> found;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. build Trie
        TrieNode* trie_root = new TrieNode;
        for (string& w : words)
            trie_root->add(w);

        // 2. search
        rows = board.size();
        cols = board[0].size();
        found = {};

        // overwrite letters as you go
        // remove words from trie when found
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                string word;
                findEnd(r, c, trie_root, word, board);
            }
        }
        return found;
    }

  private:
    void findEnd(int r, int c, TrieNode* node, string& word, vector<vector<char>>& board) {
        if (board[r][c] == 0) return;

        if (!node->chars.contains(board[r][c]))
            return;
        
        word.push_back(board[r][c]);
        board[r][c] = 0;
        node = node->chars[word.back()];

        if (node->word_end) {
            node->word_end = false;
            found.push_back(word);
        }

        // up, down, left, right
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : directions) {
            if (inRange(r + d.front(), c + d.back()))
                findEnd(r+d.front(), c+d.back(),
                    node,
                    word, board);
        }
        
        board[r][c] = word.back();
        word.pop_back();
    }

    bool inRange(int r, int c) {
        return r >= 0
            && r < rows
            && c >= 0
            && c < cols;
    }
};
