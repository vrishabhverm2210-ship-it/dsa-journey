1class Solution {
2public:
3int fun1( vector<int>&c ,int n,int i,int j, vector<vector<int>>&dp){
4    // base condition
5    if(i>j)return 0;
6    int res=INT_MAX;
7    if(dp[i][j]!=-1)return dp[i][j];
8    // pick random no. in between i and j
9    for(int k=i;k<=j;k++){
10    int cost=c[j+1]-c[i-1];
11    int r=cost+fun1(c,n,i,k-1,dp)+fun1(c,n,k+1,j,dp);
12    res=min(res,r);
13    }
14    return dp[i][j] =res;
15}
16    int minCost(int n, vector<int>& cuts) {
17      // make our new cut vector
18      vector<int>c;
19      c.push_back(0);
20      for(int i=0;i<cuts.size();i++){
21        c.push_back(cuts[i]);
22      }            
23      c.push_back(n);
24      // now it's time for recursive call
25      sort(c.begin(),c.end());
26      int i=1;
27      int j=c.size()-2;
28      int size=c.size();
29      vector<vector<int>>dp(size);
30      for(int i=0;i<size;i++){
31        vector<int>t(size,-1);
32        dp[i]=t;
33      }
34      return fun1(c,n,i,j,dp);
35    }
36};