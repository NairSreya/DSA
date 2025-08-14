class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        // n size ka array with -1 
        vector<int> board(n,-1);
        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(0,n, board, cols, diag1, diag2, result);
        return result;
    }

    //backtrack
private: 
    void backtrack(int row, int n, vector<int>& board, unordered_set<int>&cols,unordered_set<int>& diag1, unordered_set<int>&diag2, vector<vector<string>>& result ){
        if(row == n){
            result.push_back(buildBoard(board, n));
            return;
        }
        for(int col=0; col<n;col++){
            if(isSafe(row, col, cols,diag1, diag2)){
                board[row] = col;
                cols.insert(col);
                diag1.insert(row-col);
                diag2.insert(row+col);

                backtrack(row+1, n, board, cols, diag1, diag2, result);

                cols.erase(col);
                diag1.erase(row-col);
                diag2.erase(row+col);

            }
        }
    }

    bool isSafe(int row, int col, unordered_set<int> cols,unordered_set<int> diag1, unordered_set<int> diag2 ){
        if(cols.count(col)){
            return false;
        }
        if(diag1.count(row-col)){
            return false;
        }
        if(diag2.count(row+col)){
            return false;
        }
        return true;
    }
    vector<string> buildBoard(vector<int>& board, int n){
        vector<string> result;
        for(int row=0; row<n;row++){
            string rowStr(n , '.');
            // board[row] = col
            rowStr[board[row]] = 'Q';
            result.push_back(rowStr);
        }
        return result;
    }


};