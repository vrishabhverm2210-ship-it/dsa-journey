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
14    }
15    if (number>=10 && number<=26){
16      j2=  fun1(s,idx+2,dp);
17    }
18    return dp[idx]=j1+j2;
19   
20}
21    int numDecodings(string s) {
22        // firstly store all the alphabats in the hashmap(no need because we only have to return the ways)
23        // string number="";
24        vector<int>dp(s.size(),-1);
25        return fun1(s,0,dp);
26    }
27};