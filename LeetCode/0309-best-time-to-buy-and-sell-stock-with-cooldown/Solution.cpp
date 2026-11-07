class Solution {
public:
int fun1(vector<int>& prices,int idx,int count, vector<vector<int>>&dp){
    // base case
    if(idx>=prices.size())return 0;
    if(count==0)return 0;
    if(dp[idx][count]!=-1)return dp[idx][count];
    if(count==2){
        // we can buy
        int c1=fun1(prices,idx+1,count-1,dp)-prices[idx];
        int c2=fun1(prices,idx+1,count,dp);
        return dp[idx][count]= max(c1,c2);
    }

       int d1=fun1(prices,idx+2,count+1,dp)+prices[idx];
       int d2=fun1(prices,idx+1,count,dp);
       return dp[idx][count]= max(d1,d2);
    
}
    int maxProfit(vector<int>& prices) {
           int k=2;
        vector<vector<int>>dp(prices.size()+1);
        for(int i=0;i<prices.size();i++){
            vector<int>t(k+1,-1);
            dp[i]=t;
        }
    
        return fun1(prices,0,k,dp);
    }
};