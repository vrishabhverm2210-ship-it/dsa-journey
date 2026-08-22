1class Solution {
2public:
3
4int fun1(int n,vector<int>&cuts,int i,int j,  vector<vector<int>>&dp){
5    if(i>j)return 0;
6    int mn=INT_MAX;
7    if(dp[i][j]!=-1)return dp[i][j];
8    for(int k=i;k<=j;k++){
9     
10        int c1=fun1(n,cuts,i,k-1,dp)+fun1(n,cuts,k+1,j,dp)+cuts[j+1]-cuts[i-1];
11        mn=min(mn,c1);
12    }
13    return dp[i][j]=mn;
14}
15    int minCost(int n, vector<int>& cuts) {
16        vector<int>cut;
17        cut.push_back(0);
18        for(int i=0;i<cuts.size();i++){
19            cut.push_back(cuts[i]);
20        }
21         cut.push_back(n);
22      // now it's time for recursive call
23      sort(cut.begin(),cut.end());
24      int size=cut.size();
25        vector<vector<int>>dp(size+1);
26      for(int i=0;i<=size;i++){
27        vector<int>t(size+1,-1);
28        dp[i]=t;
29      }
30      int i=1;
31      int j=cut.size()-2;
32        return fun1(n,cut,i,j,dp);
33    }
34};