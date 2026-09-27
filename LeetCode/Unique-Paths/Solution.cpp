1class Solution {
2public:
3int fun1(int i,int j,int n,int m,vector<vector<int>>&dp){
4    if(i==n-1&&j==m-1)return 1;
5      if(dp[i][j]!=-1)return dp[i][j];
6    if(i<0||i>=n||j<0||j>=m)return 0;
7  
8    return dp[i][j]=fun1(i+1,j,n,m,dp)+fun1(i,j+1,n,m,dp);
9}
10    int uniquePaths(int m, int n) {
11         vector<vector<int>>dp(n+1);
12         for(int i=0;i<=n;i++){
13            vector<int>t(m+1,-1);
14            dp[i]=t;
15         }
16        return fun1(0,0,n,m,dp);
17    }
18};