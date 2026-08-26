1class Solution {
2public:
3int  fun1(vector<int>& prices,int k,int idx,vector<vector<int>>&dp){
4    if(idx==prices.size()){
5        return 0 ;
6    }
7    if(k==0)return 0;
8   if(dp[idx][k]!=-1)return dp[idx][k];
9    if(k==2){
10        // we have choice to buy
11        int c1=fun1(prices,k-1,idx+1,dp)-prices[idx];
12        int c2=fun1(prices,k,idx+1,dp);
13        return dp[idx][k]=max(c1,c2);
14    }
15  // we have choice to sell
16        int c1=fun1(prices,k-1,idx+1,dp)+prices[idx];
17        int c2=fun1(prices,k,idx+1,dp);
18        return dp[idx][k]=max(c1,c2);
19    
20
21}
22    int maxProfit(vector<int>& prices) {
23        int k=2;
24         vector<vector<int>>dp(prices.size()+1);
25         for(int i=0;i<=prices.size();i++){
26            vector<int>t(k+1,-1);
27            dp[i]=t;
28         }
29        // return  fun1(prices, k,0,dp);
30int n=prices.size();
31
32        // intialise according to the base case
33        for(int i=0;i<=prices.size();i++){
34            dp[i][0]=0;
35        }
36        for(int i=0;i<=k;i++){
37            dp[n][i]=0;
38        }
39        for(int i=n-1;i>=0;i--){
40            for(int j=1;j<=k;j++){
41                 if(j==2){
42                dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
43                }
44                else{
45                    dp[i][j]=max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
46                }
47            }
48        }
49return dp[0][k];
50      
51    }
52};