1class Solution {
2public:
3int x[4]={-1,1,0,0};
4int y[4]={0,0,-1,1};
5bool isvalid(int row,int col,int n,int m){
6    if(row<0 || row>=n || col<0 || col>=m){
7        return false;
8    }
9    return true;
10}
11void dfs(vector<vector<int>>& grid,int i,int j,int &temp){
12      int n=grid.size();
13        int m=grid[0].size();
14        grid[i][j]=-1;
15       for(int k=0;k<4;k++){
16        int row=i+x[k];
17        int col=j+y[k];
18        if(isvalid(row,col,n,m) && grid[row][col]==1){
19            temp+=1;
20            dfs(grid,row,col,temp);
21        }
22    }
23}
24    int maxAreaOfIsland(vector<vector<int>>& grid) {
25        int maxi=INT_MIN;
26        int n=grid.size();
27        int m=grid[0].size();
28        
29        for(int i=0;i<n;i++){
30            for(int j=0;j<m;j++){
31                     int temp=1;
32                if(grid[i][j]==1){
33                     dfs(grid,i,j,temp);
34                     maxi=max(maxi,temp);
35                }
36            }
37        }
38        if(maxi==INT_MIN)return 0;
39        return maxi;
40    }
41};