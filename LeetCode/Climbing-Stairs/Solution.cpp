1class Solution {
2public:
3int fun1(int idx,int n,vector<int>&dp){
4    if(idx==n)return 1;
5    if(idx>n)return 0;
6    if(dp[idx]!=-1)return dp[idx];
7    return dp[idx]=fun1(idx+1,n,dp)+fun1(idx+2,n,dp);
8}
9    int climbStairs(int n) {
10        vector<int>dp(n+1,-1);
11        return fun1(0,n,dp);
12    }
13};