1class Solution {
2public:
3bool isSafe(int row,int col,vector<string>&board){
4    // Firstly check for col
5    for(int r=row-1;r>=0;r--){
6        if(board[r][col] =='Q'){
7            return false;
8        }
9    }
10    // for left upward diagonal(no need for downward traversal)
11    int r=row-1;
12    int c=col-1;
13    while(r>=0 && c>=0){
14        if(board[r][c]=='Q'){
15            return false;
16        }
17        r--;
18        c--;
19    }
20    // for right upward diagonal
21    int r1= row-1;
22    int c1 = col+1;
23
24while(r1 >= 0 && c1 < board.size())
25{
26    if(board[r1][c1] == 'Q')
27        return false;
28
29    r1--;
30    c1++;
31}
32return true;
33}
34void fun(int n, int row, vector<vector<string>>&ans,vector<string>&board ){
35    // Base case
36    if(row==n){
37        // queens ka track of queens also
38        ans.push_back(board);
39        return;
40    }
41    for(int col=0;col<n;col++){
42       if(isSafe(row,col,board)){
43        // place
44        board[row][col]='Q';
45        fun(n,row+1,ans,board);
46        board[row][col]='.';// Backtrack
47       }
48    // noramlly next col pe chale jao
49    }
50    return;// AGr pure col mai khi bhi nahi rkh paaye toh simply return 
51   
52}
53    vector<vector<string>> solveNQueens(int n) {
54        vector<vector<string>>ans;
55        vector<string>board(n,string(n,'.'));
56        fun(n,0,ans,board);
57        return ans;
58    }
59};