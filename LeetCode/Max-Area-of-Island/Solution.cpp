1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5
6bool isvalid(int row,int col,int n,int m ){
7    if(row >=0 && row<n && col >=0 && col<m){
8        return true;
9    }
10    return false;
11}
12void dfs(vector<vector<int>>& grid , int i,int j,int &length){
13    grid[i][j]=2;
14    int n=grid.size();
15    int m=grid[0].size();
16    for(int k=0;k<4;k++){
17        int row=i+x[k];
18        int col=j+y[k];
19      
20        if(isvalid(row,col,n,m) && grid[row][col]==1){
21            length++;
22            dfs(grid,row,col,length);
23            
24        }
25    }
26}
27    int maxAreaOfIsland(vector<vector<int>>& grid) {
28            int maxi=INT_MIN;
29            int length=1;
30        for(int i=0;i<grid.size();i++){
31            for(int j=0;j<grid[0].size();j++){
32                if(grid[i][j]==1){
33                    length=1;
34                    dfs(grid,i,j,length);
35                    maxi=max(maxi,length);
36                }
37            }
38        }
39         if(maxi==INT_MIN)return 0;
40         return maxi;
41    }
42};