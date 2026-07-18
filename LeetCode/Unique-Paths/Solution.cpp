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
17//         vector<vector<int>>dp(m+1);
18// for(int i=0;i<=m;i++){
19//     vector<int>t(n+1,-1);
20//     dp[i]=t;
21// // }
22//         return fun1(0,0,m,n,dp);
23// tabulation soltutiom
24        vector<vector<int>>dp(m+1);
25for(int i=0;i<=m;i++){
26    vector<int>t(n+1,-1);
27    dp[i]=t;
28}
29// base case
30dp[m-1][n-1]=1;
31for(int i=0;i<=n;i++){
32    dp[m][i]=0;
33}
34for(int i=0;i<=m;i++){
35    dp[i][n]=0;
36}
37// now normal loops
38for(int i=m-1;i>=0;i--){
39    for(int j=n-1;j>=0;j--){
40        if(i == m-1 && j == n-1)
41    continue;
42        dp[i][j]=dp[i+1][j]+dp[i][j+1];
43    }
44}
45return dp[0][0];
46    }
47};