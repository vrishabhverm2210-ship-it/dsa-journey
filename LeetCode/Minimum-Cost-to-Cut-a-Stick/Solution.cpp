1class Solution {
2public:
3
4int fun1(int n,vector<int>&cuts,int i,int j,  vector<vector<int>>&dp){
5    if(i>j)return 0;
6    // if(i==j)return 1;
7    int mn=INT_MAX;
8    if(dp[i][j]!=-1)return dp[i][j];
9    for(int k=i;k<=j;k++){
10     
11        int c1=fun1(n,cuts,i,k-1,dp)+fun1(n,cuts,k+1,j,dp)+cuts[j+1]-cuts[i-1];
12        mn=min(mn,c1);
13    }
14    return dp[i][j]=mn;
15}
16    int minCost(int n, vector<int>& cuts) {
17        vector<int>cut;
18        cut.push_back(0);
19        for(int i=0;i<cuts.size();i++){
20            cut.push_back(cuts[i]);
21        }
22         cut.push_back(n);
23      // now it's time for recursive call
24      sort(cut.begin(),cut.end());
25      int size=cut.size();
26        vector<vector<int>>dp(size+1);
27      for(int i=0;i<=size;i++){
28        vector<int>t(size+1,-1);
29        dp[i]=t;
30      }
31      int i=1;
32      int j=cut.size()-2;
33        return fun1(n,cut,i,j,dp);
34    }
35};