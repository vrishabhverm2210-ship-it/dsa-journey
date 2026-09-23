1class Solution {
2public:
3int fun1(int i,int j,int n,int m,vector<vector<int>>&dp){
4    if(i==n-1 && j==m-1){
5        return 1;
6    }
7    if(dp[i][j]!=-1)return dp[i][j];
8    // unsafe condition
9    if(i>=n||i<0||j>=m||j<0)return 0;
10
11    return dp[i][j]=fun1(i+1,j,n,m,dp)+ fun1(i,j+1,n,m,dp);
12}
13    int uniquePaths(int n, int m) {
14        vector<vector<int>>dp(n+1);
15        for(int i=0;i<=n;i++){
16            vector<int>t(m+1,-1);
17            dp[i]=t;
18        }
19        return fun1(0,0,n,m,dp);
20    }
21};