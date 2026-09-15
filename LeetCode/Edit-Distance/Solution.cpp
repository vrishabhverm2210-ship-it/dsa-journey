1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        // FIND LCS
5        int n=word1.size();
6        int m=word2.size();
7        vector<vector<int>>dp(n+1);
8        for(int i=0;i<=n;i++){
9            vector<int>t(m+1,-1);
10            dp[i]=t;
11        }
12        for(int i=0;i<=m;i++){
13            dp[0][i]=i;
14        }
15        for(int i=0;i<=n;i++){
16            dp[i][0]=i;
17        }
18        for(int i=1;i<=n;i++){
19            for(int j=1;j<=m;j++){
20            if(word1[i-1]==word2[j-1]){
21                dp[i][j]=dp[i-1][j-1];
22                
23            }
24            else{
25                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
26            }
27            }
28        }
29        return dp[n][m];
30    }
31};