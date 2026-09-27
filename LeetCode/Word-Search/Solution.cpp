1class Solution {
2public:
3bool isfound=false;
4int x[4]={-1,1,0,0};
5int y[4]={0,0,-1,1};
6
7bool isvalid(int row,int col,int n,int m ){
8    if(row >=0 && row<n && col >=0 && col<m){
9        return true;
10    }
11    return false;
12}
13void dfs(vector<vector<char>>& board,int i,int j ,string word,int idx){
14      int n=board.size();
15        int m=board[0].size();
16    int size=word.size();
17    if(size-1==idx ){
18        isfound=true;
19        return;
20    }
21    char original=board[i][j];
22  // mark visited
23        board[i][j] = '-1';
24    for(int k=0;k<4;k++){
25        int row=i+x[k];
26        int col=j+y[k];
27        if(isvalid(row,col,n,m)&&board[row][col]==word[idx+1]){
28            dfs(board,row,col,word,idx+1);
29        }
30    }
31    // backtrack
32    board[i][j]=original;
33}
34    bool exist(vector<vector<char>>& board, string word) {
35        int n=board.size();
36        int m=board[0].size();
37    for(int i=0;i<n;i++){
38        for(int j=0;j<m;j++){
39            if(board[i][j]==word[0]){
40                dfs(board,i,j,word,0);
41                if(isfound)return true;
42            }
43        }
44    }
45    return false;
46    }
47};