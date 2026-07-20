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
19    int maxProfit(int k, vector<int>& prices) {
20    //               int n=prices.size();
21    //     int k1=2*k; // tehnically 2 baar buy and 2 baar sell
22    //     vector<vector<int>>dp(n+1);
23    //     for(int i=0;i<=n;i++){
24    //         vector<int>t(k1+1,-1);
25    //         dp[i]=t;
26    //     }
27    //   return fun1(prices,n,0,k1,dp);
28              int n=prices.size();
29           int k1=2*k;
30        vector<vector<int>>dp(n+1);
31        for(int i=0;i<=n;i++){
32            vector<int>t(k1+1,-1);
33            dp[i]=t;
34        }
35        // fill the 0th column
36        for(int i=0;i<=n;i++){
37            dp[i][0]=0;
38        }
39        // fill the nth row
40        for(int i=0;i<=k1;i++){
41            dp[n][i]=0;
42        }
43        // now run a normal loop
44        for(int i=n-1;i>=0;i--){
45            for(int j=1;j<=k1;j++){
46                if(j%2==0){
47                dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
48                }
49                else{
50                    dp[i][j]=max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
51                }     
52            }
53        }
54return dp[0][k1];
55    }
56};