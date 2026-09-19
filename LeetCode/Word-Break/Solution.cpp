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
11  // means  check every word 
12
13    for(int j=idx;j<n;j++){
14       string word=s.substr(idx,j-idx+1);
15       //if we able to find that word in the set then cut the word and try new if again we able to reach at the end then return true
16       if(set.count(word)){  // checking whether word present or not
17         if(fun1(s,set,j+1,dp)){    // if this comes true only then return true
18            return dp[idx]= true;  
19       }
20     }
21    }
22    // if after traversing the whole loop still we can't find the valid thing then return false;
23return dp[idx]=false;
24
25
26}
27    bool wordBreak(string s, vector<string>& wordDict) {
28        unordered_set<string>set;
29        vector<int>dp(s.size(),-1);
30        for(int i=0;i<wordDict.size();i++){
31            set.insert(wordDict[i]);
32        }
33        return fun1(s,set,0,dp);
34    }
35};