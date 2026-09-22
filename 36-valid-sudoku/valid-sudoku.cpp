class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> rows(9);
        vector<unordered_map<int,int>> col(9);
        vector<unordered_map<int,int>> grid(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                // row
                if(board[i][j]=='.') continue;
                if(rows[i].count(board[i][j])>0){
                    return false;
                }
                rows[i][board[i][j]]=1;

                // col
                if(col[j].count(board[i][j])>0){
                    return false;
                }
                col[j][board[i][j]]=1;

                // grid
                int nR=i/3;
                int nC=j/3;
                int index = nR*3 + nC;
                if(grid[index].count(board[i][j])>0){
                    return false;
                }

                grid[index][board[i][j]]=1;
            }
        }


        return true;
    }
};