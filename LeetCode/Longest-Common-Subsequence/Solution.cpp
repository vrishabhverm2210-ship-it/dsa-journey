1class Solution {
2public:
3int fun1(string text1, string text2,int n,int m, vector<vector<int>>&dp){
4   if(n==0||m==0)return 0;
5   if(dp[n][m]!=-1)return dp[n][m];
6    if(text1[n-1]==text2[m-1]){
7      return  dp[n][m]=  1+fun1(text1,text2,n-1,m-1,dp);
8    }
9  
10        int c1=fun1(text1,text2,n-1,m,dp);
11        int c2=fun1(text1,text2,n,m-1,dp);
12        return dp[n][m]= max(c1,c2);
13   
14
15}
16    int longestCommonSubsequence(string text1, string text2) {
17        int n=text1.size();
18        int m=text2.size();
19        vector<vector<int>>dp(text1.size()+1);
20        for(int i=0;i<=text1.size();i++){
21            vector<int>t(text2.size()+1,-1);
22            dp[i]=t;
23        }
24    //    return fun1(text1,text2,text1.size(),text2.size(),dp); 
25    //      // return fun1(text1,text2,n,m,dp);
26        for(int i=0;i<=n;i++){
27            dp[i][0]=0;
28        }
29        for(int j=0;j<=m;j++){
30            dp[0][j]=0;
31        }
32        for(int i=1;i<=n;i++){
33            for(int j=1;j<=m;j++){
34                if(text1[i-1]==text2[j-1]){
35                    dp[i][j]=1+dp[i-1][j-1];
36                }
37                else{
38                  dp[i][j]=  max(dp[i-1][j] , dp[i][j-1]);
39                }
40            }
41        }
42return dp[n][m];
43    }
44};