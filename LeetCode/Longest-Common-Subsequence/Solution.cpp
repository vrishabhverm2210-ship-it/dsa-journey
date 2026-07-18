1class Solution {
2public:
3// int fun1(string text1, string text2,int i,int j){
4//     if(i==text1.size() || j== text2.size() ){
5//         return 0;
6//     }
7//     // we have 1 case when both are equal
8//     if(text1[i]==text2[j]){
9//         return 1+fun1(text1,text2,i+1,j+1);
10//     }
11//     // now we have two choices kisi ek ko toh aage bhadna hi pdega
12//     int c1=fun1(text1,text2,i+1,j);
13//     int c2=fun1(text1,text2,i,j+1);
14//     return max(c1,c2);
15// }
16    int longestCommonSubsequence(string text1, string text2) {
17        // return fun1(text1,text2,0,0);
18        // make 2d vector
19        int n=text1.size();
20        int m=text2.size();
21        vector<vector<int>>dp(n+1);
22        for(int i=0;i<=n;i++){
23            vector<int>t(m+1,-1);
24            dp[i]=t;
25        }
26        // now according to base case fill the matrix
27        for(int i=0;i<=m;i++){
28            dp[n][i]=0;
29        }
30         for(int i=0;i<=n;i++){
31            dp[i][m]=0;
32        }
33        // now normal loops ulti chlegi
34        for(int i=n-1;i>=0;i--){
35            for(int j=m-1;j>=0;j--){
36                if(text1[i]==text2[j]){
37                    dp[i][j]=1+dp[i+1][j+1];
38                }
39                else{
40                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
41                }
42            }
43        }
44return dp[0][0];
45    }
46};