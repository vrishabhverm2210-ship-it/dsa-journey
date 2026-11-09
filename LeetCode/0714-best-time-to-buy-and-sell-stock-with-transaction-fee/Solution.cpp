class Solution {
public:
int fun1(vector<int>& prices,int n, int idx,int k,vector<vector<int>>&dp,int fee){
    if(idx>=n)return 0;
    // if(k==0)return 0;
    if(dp[idx][k]!=-1)return dp[idx][k];
    if(k==2){   //  buying opportunity hai
    int c1=fun1(prices,n,idx+1,k-1,dp,fee)-prices[idx];
    int c2=fun1(prices,n,idx+1,k,dp,fee);
    return dp[idx][k]= max(c1,c2);
    }
    else{
        int d1=fun1(prices,n,idx+1,k+1,dp,fee)+prices[idx]-fee;
          int d2=fun1(prices,n,idx+1,k,dp,fee);
          return  dp[idx][k]=max(d1,d2);
    }
    
}
    int maxProfit(vector<int>& prices, int fee) {
          int n=prices.size();
        int k=2;
        vector<vector<int>>dp(n+1);
        for(int i=0;i<=n;i++){
            vector<int>t(k+1,-1);
            dp[i]=t;
        }
      return fun1(prices,n,0,2,dp,fee);
    }
};