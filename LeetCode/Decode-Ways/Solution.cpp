1class Solution {
2public:
3int fun1(string s, int idx,vector<int>&dp){
4    if(idx>=s.size())return 1;
5    if(s[idx] == '0')return 0;  // A standalone '0' is invalid.
6
7if(dp[idx]!=-1)return dp[idx];
8    // jump 1 call
9    int j2=0;
10    int j1=  fun1(s,idx+1,dp);
11    int number=0;
12    if(idx+1<s.size()){
13        number=(s[idx]-'0')*10 + (s[idx+1]-'0');
14         if (number>=10 && number<=26){
15      j2=  fun1(s,idx+2,dp);
16    }
17    }
18   
19    return dp[idx]=j1+j2;
20   
21}
22    int numDecodings(string s) {
23        // firstly store all the alphabats in the hashmap(no need because we only have to return the ways)
24        // string number="";
25        vector<int>dp(s.size(),-1);
26        return fun1(s,0,dp);
27    }
28};