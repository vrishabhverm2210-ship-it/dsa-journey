1class Solution {
2public:
3int ways=0;
4bool isSafe(int row,int col,vector<string>&board){
5    // Firstly check for col
6    for(int r=row-1;r>=0;r--){
7        if(board[r][col] =='Q'){
8            return false;
9        }
10    }
11      // for left upward diagonal(no need for downward traversal)
12    int r=row-1;
13    int c=col-1;
14    while(r>=0 && c>=0){
15        if(board[r][c]=='Q'){
16            return false;
17        }
18        r--;
19        c--;
20    }
21    // for right upward diagonal
22    int r1= row-1;
23    int c1 = col+1;
24
25while(r1 >= 0 && c1 < board.size())
26{
27    if(board[r1][c1] == 'Q')
28        return false;
29
30    r1--;
31    c1++;
32}
33return true;
34}
35
36 void fun(int n, int row, vector<vector<string>>&ans,vector<string>&board ){
37    // Base case
38    if(row==n){
39        // queens ka track of queens also
40        ans.push_back(board);
41        ways++;
42        return;
43    }
44    for(int col=0;col<n;col++){
45       if(isSafe(row,col,board)){
46        // place
47        board[row][col]='Q';
48        fun(n,row+1,ans,board);
49        board[row][col]='.';// Backtrack
50       }
51    // noramlly next col pe chale jao
52    }
53    return;// AGr pure col mai khi bhi nahi rkh paaye toh simply return 
54   
55}
56    int totalNQueens(int n) {
57           vector<vector<string>>ans;
58        vector<string>board(n,string(n,'.'));
59        fun(n,0,ans,board);
60        return  ways;
61    }
62};