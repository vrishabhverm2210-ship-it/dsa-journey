1class Solution {
2public:
3int fun1(string &text1,string &text2,int i,int j, vector<vector<int>>&dp){
4    if(i==0 || j==0 )return 0;
5    // Choice 1
6    if(dp[i][j]!=-1)return dp[i][j];
7    if(text1[i-1]==text2[j-1]){
8        return dp[i][j]=1+fun1(text1,text2,i-1,j-1,dp);
9    }
10    int c1=fun1(text1,text2,i-1,j,dp);
11    int c2=fun1(text1,text2,i,j-1,dp);
12    return dp[i][j]= max(c1,c2);
13}
14    int longestCommonSubsequence(string text1, string text2) {
15        int n=text1.size();
16        int m=text2.size();
17        vector<vector<int>>dp(n+1);
18        for(int i=0;i<=n;i++){
19            vector<int>t(m+1,-1);
20            dp[i]=t;
21        }
22        return fun1(text1,text2,n,m,dp);
23    }
24};