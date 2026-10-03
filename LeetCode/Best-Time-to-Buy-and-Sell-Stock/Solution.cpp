1class Solution {
2public:
3int fun1(vector<int>& prices,int idx,int k, vector<vector<int>>&dp){
4    if(idx==prices.size())return 0;
5    if(k==0)return 0;
6    if(dp[idx][k]!=-1)return dp[idx][k];
7    if(k==2){
8        int c1= fun1(prices,idx+1,k-1,dp)-prices[idx];
9        int c2=fun1(prices,idx+1,k,dp);
10        return dp[idx][k]= max(c1,c2);
11    }
12    
13        int c1=prices[idx]+fun1(prices,idx+1,k-1,dp);
14        int c2=fun1(prices,idx+1,k,dp);
15    return dp[idx][k]=max(c1,c2);
16
17}
18    int maxProfit(vector<int>& prices) {
19     int n=prices.size();
20        int k=2;
21        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
22        
23      return  fun1(prices,0,k,dp);
24    }
25};