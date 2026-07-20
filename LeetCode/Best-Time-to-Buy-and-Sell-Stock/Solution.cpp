1class Solution {
2public:
3int fun1(vector<int>& prices,int n,int idx,int k,  vector<vector<int>>&dp){
4    if(idx==n)return 0;
5    if(k==0)return 0;
6    if(dp[idx][k]!=-1)return dp[idx][k];
7    if(k==2){
8        // we have to choices whether to buy or not
9        int c1=fun1(prices,n,idx+1,k-1,dp)-prices[idx];
10        int c2=fun1(prices,n,idx+1,k,dp);
11        return dp[idx][k]=max(c1,c2);
12    }
13    // we have two choices for the selling either to sell or notu
14    int d1=fun1(prices,n,idx+1,k-1,dp)+prices[idx];
15        int d2=fun1(prices,n,idx+1,k,dp);
16        return  dp[idx][k]=max(d1,d2);
17}
18
19    int maxProfit(vector<int>& prices) {
20        // int n=prices.size();
21        // int k=2;
22        // vector<vector<int>>dp(n+1);
23        // for(int i=0;i<=n;i++){
24        //     vector<int>t(k+1,-1);
25        //     dp[i]=t;
26        // }
27        // return fun1(prices,n,0,k,dp);
28
29        // let's try to convert it into tabulation
30          int n=prices.size();
31           int k=2;
32        vector<vector<int>>dp(n+1);
33        for(int i=0;i<=n;i++){
34            vector<int>t(k+1,-1);
35            dp[i]=t;
36        }
37        // fill the 0th column
38        for(int i=0;i<=n;i++){
39            dp[i][0]=0;
40        }
41        // fill the nth row
42        for(int i=0;i<=2;i++){
43            dp[n][i]=0;
44        }
45        // now run a normal loop
46        for(int i=n-1;i>=0;i--){
47            for(int j=1;j<=k;j++){
48                if(j==2){
49                dp[i][j]=max(dp[i+1][j-1]-prices[i],dp[i+1][j]);
50                }
51                else{
52                    dp[i][j]=max(dp[i+1][j-1]+prices[i],dp[i+1][j]);
53                }     
54            }
55        }
56return dp[0][k];
57    }
58};