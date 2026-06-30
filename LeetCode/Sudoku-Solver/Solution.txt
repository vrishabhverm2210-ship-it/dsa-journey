1class Solution {
2public:
3bool isValid(vector<vector<char>>& board,char val,int row,int col){
4    // Check for row
5    for(int i=0;i<9;i++){
6        if(board[row][i]== val)return false;
7    // check for col
8        if(board[i][col]== val)return false;
9    // for 3*3 grid
10        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
11            return false;
12        }
13}
14    return true;
15}
16bool fun(vector<vector<char>>& board){
17    for(int i=0;i<board.size();i++){
18        for(int j=0;j<board.size();j++){
19            if(board[i][j] == '.'){
20                for(int val='1';val<='9';val++){
21                    if(isValid(board,val,i,j)){
22                       board[i][j]=val;
23                    if(fun(board))return true;// check krenge ki kahi solve toh nahi ho gya
24                       board[i][j] = '.';
25                }
26            }
27            return false;
28        }
29    }
30}
31return true;
32}
33    void solveSudoku(vector<vector<char>>& board) {
34         fun(board);
35    }
36};