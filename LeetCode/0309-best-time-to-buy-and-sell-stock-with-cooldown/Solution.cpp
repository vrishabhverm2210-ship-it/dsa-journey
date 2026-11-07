class Solution {
public:
int fun1(vector<int>&prices,int n,int idx,int k,vector<vector<int>>&dp){
    if(idx>=n)return 0;

    if(dp[idx][k]!=-1)return dp[idx][k];

    if(k==2){
        int c1=fun1(prices,n,idx+1,k-1,dp)-prices[idx];
        int c2=fun1(prices,n,idx+1,k,dp);
        return dp[idx][k]=  max(c1,c2);
    }
    else{
        int c1=fun1(prices,n,idx+2,k+1,dp)+prices[idx];
        int c2=fun1(prices,n,idx+1,k,dp);
        return dp[idx][k]= max(c1,c2);
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
int k=2;
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return fun1(prices,n,0,2,dp);
    }
};