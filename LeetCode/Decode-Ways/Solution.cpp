1class Solution {
2public:
3int fun2(string s,int idx,vector<int>&dp){
4    int n=s.size();
5    if(n==idx)return 1;
6    if(dp[idx]!=-1)return dp[idx];
7    if(s[idx]=='0')return 0;
8   int ways=0;
9    // take case of 1 digit
10    ways+=fun2(s,idx+1,dp);
11    
12   // Take 2 digits
13        if (idx + 1 < n) {
14
15// string to integer
16            int num = stoi(s.substr(idx, 2));
17
18            if (num <= 26) {
19                ways += fun2(s, idx + 2,dp);
20            }
21        }
22return dp[idx]= ways;
23
24}
25    int numDecodings(string s) {
26        int n=s.size();
27        vector<int>dp(n+1,-1);
28        return fun2(s,0,dp);
29    }
30};