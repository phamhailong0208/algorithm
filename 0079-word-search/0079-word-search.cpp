class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, int index, int row, int col, string word) {
        if (index == word.length()) return true;
        if (r<0 || r>= row || c <0 || c>=col || board[r][c] != word[index]) return false;
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board,r-1,c,index+1,row, col, word) ||
                     dfs(board,r+1,c,index+1,row, col, word) ||
                     dfs(board,r,c-1,index+1,row, col, word) ||
                     dfs(board,r,c+1,index+1,row, col, word) ;
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for (int i=0; i < row; i++) {
            for (int j=0; j < col; j++) {
                if (dfs(board, i, j, 0, row, col, word)) return true;
            }
        }
        return false;
    }
};