1class Solution {
2public:
3int fun1(vector<int>& prices,int n, int idx,int k,vector<vector<int>>&dp){
4    if(idx==n)return 0;
5    if(k==0)return 0;
6    if(dp[idx][k]!=-1)return dp[idx][k];
7    if(k%2==0){   //  buying opportunity hai
8    int c1=fun1(prices,n,idx+1,k-1,dp)-prices[idx];
9    int c2=fun1(prices,n,idx+1,k,dp);
10    return dp[idx][k]= max(c1,c2);
11    }
12    else{
13        int d1=fun1(prices,n,idx+1,k-1,dp)+prices[idx];
14          int d2=fun1(prices,n,idx+1,k,dp);
15          return  dp[idx][k]=max(d1,d2);
16    }
17    
18}
19    int maxProfit(vector<int>& prices) {
20    //         int n=prices.size();
21    //     int k=4; // tehnically 2 baar buy and 2 baar sell
22    //     vector<vector<int>>dp(n+1);
23    //     for(int i=0;i<=n;i++){
24    //         vector<int>t(k+1,-1);
25    //         dp[i]=t;
26    //     }
27    //   return fun1(prices,n,0,k,dp);
28
29              int n=prices.size();
30           int k=4;
31        vector<vector<int>>dp(n+1);
32        for(int i=0;i<=n;i++){
33            vector<int>t(k+1,-1);
34            dp[i]=t;
35        }
36        // fill the 0th column
37        for(int i=0;i<=n;i++){
38            dp[i][0]=0;
39        }
40        // fill the nth row
41        for(int i=0;i<=k;i++){
42            dp[n][i]=0;
43        }
44        // now run a normal loop
45        for(int i=n-1;i>=0;i--){
46            for(int j=1;j<=k;j++){
47                if(j%2==0){
48                dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
49                }
50                else{
51                    dp[i][j]=max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
52                }     
53            }
54        }
55return dp[0][k];
56    }
57};