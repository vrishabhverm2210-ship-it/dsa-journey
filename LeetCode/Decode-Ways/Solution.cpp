1class Solution {
2public:
3int fun1(string s,int idx, vector<int>&dp){
4    int n=s.size();
5    if(idx==n)return 1;
6    if(dp[idx]!=-1)return dp[idx];
7    if(s[idx]=='0')return 0;
8    int c1=fun1(s,idx+1,dp);
9int c2=0;
10    // do ko lene ki baari
11     // Take 2 digits
12        if (idx + 1 < n) {
13    string num=s.substr(idx,2);
14    if(num>="10" && num<="26"){
15        c2=fun1(s,idx+2,dp);
16    }
17        }
18    return dp[idx]= c1+c2;
19    
20}
21    int numDecodings(string s) {
22        int n=s.size();
23        vector<int>dp(n+1,-1);
24        return fun1(s,0,dp);
25    }
26};