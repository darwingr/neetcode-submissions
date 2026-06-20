// DFS from side cells
//  O(m x n)
//  O(m x n)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++)
            for (size_t j : {size_t{0}, board[0].size()-1})
                if (board[i][j] == 'O')
                    dfs(board, i, j);

        for (int j=0; j<board[0].size(); j++)
            for (size_t i : {size_t{0}, board.size()-1})
                if (board[i][j] == 'O')
                    dfs(board, i, j);

        for (int i=1; i<board.size()-1; i++)
            for (int j=1; j<board[0].size()-1; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                if (board[i][j] == 'U')
                    board[i][j] = 'O';
    }

    void dfs(vector<vector<char>>& board, int r, int c)
    {
        if (r < 0 ||
            c < 0 ||
            r >= board.size() ||
            c >= board[0].size() ||
            board[r][c] != 'O')
            return;

        board[r][c] = 'U';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r,   c-1);
        dfs(board, r,   c+1);
    }
};
