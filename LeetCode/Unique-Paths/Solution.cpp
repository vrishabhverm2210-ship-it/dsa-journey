1class Solution {
2public:
3
4int fun1(int i,int j, int m, int n,vector<vector<int>>&dp){
5    if(i==m-1 && j==n-1){
6        return 1;
7    }
8    // outside the matrix
9    if(i<0 || i>=m || j>=n || j<0){
10        return 0;
11    }
12    if(dp[i][j]!=-1)return dp[i][j];
13    // now i have only two choices
14    return dp[i][j]=fun1(i+1,j,m,n,dp)+fun1(i,j+1,m,n,dp);
15}
16    int uniquePaths(int m, int n) {
17        vector<vector<int>>dp(m+1);
18for(int i=0;i<=m;i++){
19    vector<int>t(n+1,-1);
20    dp[i]=t;
21}
22        return fun1(0,0,m,n,dp);
23    }
24};