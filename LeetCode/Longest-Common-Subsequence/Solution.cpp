1class Solution {
2public:
3int fun1(string &text1, string &text2,int  n ,int m,vector<vector<int>> &dp){
4    if(n==0 || m==0){
5        return 0;
6    }
7    if(dp[n][m]!=-1)return dp[n][m];
8    if(text1[n-1]==text2[m-1]){
9        return  dp[n][m]=1+fun1(text1,text2,n-1,m-1,dp);
10    }
11    // we have two choices
12
13    int c1=fun1(text1,text2,n-1,m,dp);
14    int c2=fun1(text1,text2,n,m-1,dp);
15    return dp[n][m]= max(c1,c2);
16}
17    int longestCommonSubsequence(string text1, string text2) {
18        // recursive code ->think of a smlestvalid input
19        // choice diagram 
20        // how we can decrease our size
21        // for memoization let's make the dp array
22        int n=text1.size();
23          int m=text2.size();      
24        // vector<vector<int>>dp(n+1);
25        // for(int i=0;i<=n;i++){
26        //      vector<int>t(m+1,-1);
27        //      dp[i]=t;
28        // }
29        // return fun1(text1,text2,text1.size(),text2.size(),dp);
30        // now let's do it's bottom up
31          vector<vector<int>>dp(n+1);
32        for(int i=0;i<=n;i++){
33             vector<int>t(m+1,-1);
34             dp[i]=t;
35        }
36        // initialise according to the base case
37        for(int i=0;i<=n;i++){
38            dp[i][0]=0;
39        }
40        for(int i=0;i<=m;i++){
41            dp[0][i]=0;
42        }
43        // now fill the remaining pllaces of matrix using the normal loops
44        for(int i=1;i<=n;i++){
45            for(int j=1;j<=m;j++){
46                if(text1[i-1]==text2[j-1]){
47                    dp[i][j]=1+dp[i-1][j-1];
48                }
49                else{
50                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
51                }
52            }
53        }
54        return dp[n][m];
55    }
56};