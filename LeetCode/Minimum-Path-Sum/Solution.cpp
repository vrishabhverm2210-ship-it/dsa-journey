1class Solution {
2public:
3int ans=INT_MAX;
4int fun1(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
5    // base case
6    int n=grid.size();
7    int m=grid[0].size();
8         // unsafe condition
9        
10    if(i>=n||i<0||j>=m||j<0)return INT_MAX;
11
12        // Destination
13        if(i == n-1 && j == m-1)
14            return grid[i][j];
15
16    if(dp[i][j]!=-1)return dp[i][j];
17       int low=fun1(grid,i+1,j,dp);
18          int right=fun1(grid,i,j+1,dp);
19
20          return  dp[i][j] = grid[i][j]+min(low,right);
21    
22 
23
24}
25    int minPathSum(vector<vector<int>>& grid) {
26         int n=grid.size();
27         int m=grid[0].size();
28        int sum=0;
29        vector<vector<int>>dp(n+1);
30        for(int i=0;i<=n;i++){
31            vector<int>t(m+1,-1);
32            dp[i]=t;
33        }
34      return  fun1(grid,0,0,dp);
35    
36    }
37};