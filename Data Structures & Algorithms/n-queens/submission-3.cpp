// backtracking, no pruning
//  O(N!)
//  O(N^2)
class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<int> columns;
        dfs(n, columns);
        return res;
    }

    void dfs(const int n, vector<int>& cols) {
        if (cols.size() == n) {
            printRes(cols);
            return;
        }
        int new_q_row = cols.size();
        for (int new_q_col=0; new_q_col<n; new_q_col++) {
            if (new_q_fits(cols, {new_q_row, new_q_col})) {
                cols.push_back(new_q_col);
                dfs(n, cols);
                cols.pop_back();
            }
        }
    }

    bool new_q_fits(vector<int>& cols, pair<int,int> new_q) const {
        for (int old_q_row=0; old_q_row<cols.size(); old_q_row++) {
            int old_q_col = cols[old_q_row];
            if (!noattack({old_q_row, old_q_col}, new_q))
                return false;
        }
        return true;
    }
    
    bool noattack(pair<int,int> q1, pair<int,int> q2) const {
        int diff_rows = abs(q1.first  - q2.first);
        int diff_cols = abs(q1.second - q2.second);
        return diff_rows != 0
            && diff_cols != 0
            && diff_rows != diff_cols;
    }

    void printRes(vector<int>& cols) {
        vector<string> places;
        for (int row_col : cols) {
            string row = "";
            for (int col=0; col<cols.size(); col++) {
                if (col == row_col)
                    row += 'Q';
                else
                    row += '.';
            }
            places.push_back(row);
        }
        res.push_back(places);
    }
};
