class Solution {
public:
    bool isSafeCell(int row, int col, vector<string> &board){
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }

        int nr = row-1, nc = col+1;
        while(nr>=0 && nc < board.size()){
            if(board[nr][nc] == 'Q') return false;
            nr--;
            nc++;
        }

        nr = row-1, nc = col-1;
        while(nr>=0 && nc>=0){
            if(board[nr][nc] == 'Q') return false;
            nr--;
            nc--;
        }
        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col< n; col++){
            if(isSafeCell(row, col, board)){
                board[row][col] = 'Q';
                solve(row+1, board, ans, n);
                board[row][col] = '.';
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        solve(0, board, ans, n);
        return ans;
    }
};