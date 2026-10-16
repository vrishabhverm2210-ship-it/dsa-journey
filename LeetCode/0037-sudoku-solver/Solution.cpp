class Solution {
public:
bool isValid(vector<vector<char>>& board,char val,int row,int col){
    // Check for row
    for(int i=0;i<9;i++){
        if(board[row][i]== val)return false;
    // check for col
        if(board[i][col]== val)return false;
    // for 3*3 grid
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
}
    return true;
}
bool fun(vector<vector<char>>& board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j] == '.'){
                for(int val='1';val<='9';val++){
                    if(isValid(board,val,i,j)){
                       board[i][j]=val;
                    if(fun(board))return true;// check krenge ki kahi solve toh nahi ho gya
                       board[i][j] = '.';
                }
            }
            return false;
        }
    }
}
return true;
}
    void solveSudoku(vector<vector<char>>& board) {
         fun(board);
    }
};