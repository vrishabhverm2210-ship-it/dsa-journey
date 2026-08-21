1class Solution {
2public:
3int fun1(vector<int>& prices,int idx,int count, vector<vector<int>>&dp){
4    // base case
5    if(idx==prices.size())return 0;
6    if(count==0)return 0;
7    if(dp[idx][count]!=-1)return dp[idx][count];
8    if(count==2){
9        // we can buy
10        int c1=fun1(prices,idx+1,count-1,dp)-prices[idx];
11        int c2=fun1(prices,idx+1,count,dp);
12        return dp[idx][count]= max(c1,c2);
13    }
14
15       int d1=fun1(prices,idx+1,count-1,dp)+prices[idx];
16       int d2=fun1(prices,idx+1,count,dp);
17       return dp[idx][count]= max(d1,d2);
18    
19}
20    int maxProfit(vector<int>& prices) {
21            int k=2;
22        vector<vector<int>>dp(prices.size()+1);
23        for(int i=0;i<prices.size();i++){
24            vector<int>t(k+1,-1);
25            dp[i]=t;
26        }
27    
28        return fun1(prices,0,k,dp);
29    }
30};