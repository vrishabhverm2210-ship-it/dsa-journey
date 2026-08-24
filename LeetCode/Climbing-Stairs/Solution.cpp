1class Solution {
2public:
3int fun1(int n, int i,vector<int>&dp){
4    // base condition
5    if(i==n)return 1;
6    if(i>n)return 0;
7    if(dp[i]!=-1)return dp[i];
8    // now i have two choices from the ground level
9    int c1=fun1(n,i+1,dp);
10    int c2=fun1(n,i+2,dp);
11    return dp[i]=c1+c2;
12}
13    int climbStairs(int n) {
14        vector<int>dp(n+1,-1);
15        // return fun1(n,0,dp);
16        dp[n]=1;
17        for(int i=n-1;i>=0;i--){
18            int c1=dp[i+1];
19            if(i==n-1) {
20                dp[i]=dp[i+1];
21                continue;
22            }
23            int c2=dp[i+2];
24            dp[i]=c1+c2;
25
26        }
27        return dp[0];
28    }
29};