1class Solution {
2public:
3bool fun1(string s, unordered_set<string>&set,int idx,vector<int>&dp ){
4    int n=s.size();
5    if(idx==n){
6         return true;
7    }
8
9    if(dp[idx] != -1)
10        return dp[idx];
11
12    for(int j=idx;j<n;j++){
13       string word=s.substr(idx,j-idx+1);
14       if(set.count(word)){
15         if(fun1(s,set,j+1,dp)){
16            return dp[idx]= true;
17       }
18     }
19    }
20return dp[idx]=false;
21
22
23}
24    bool wordBreak(string s, vector<string>& wordDict) {
25        unordered_set<string>set;
26        vector<int>dp(s.size(),-1);
27        for(int i=0;i<wordDict.size();i++){
28            set.insert(wordDict[i]);
29        }
30        return fun1(s,set,0,dp);
31    }
32};