1class Solution {
2public:
3    bool isMatch(string s, string p) {
4        
5    int n=s.size();
6    int m=p.size();
7
8     vector<vector<bool>>dp(n+1);
9        for(int i=0;i<=n;i++){
10            vector<bool>t(m+1,0);
11            dp[i]=t;
12        }
13        // initialise the base conditions
14        // for(int i=0;i<=n;i++){
15        //     dp[i][0]=1;
16        // }
17        // for(int i=0;i<=m;i++){
18        //     dp[0][i]=1;
19        // }
20        dp[0][0]=1;
21        for(int i=1;i<=m;i++){
22            if(p[i-1]=='*'){
23                dp[0][i]=dp[0][i-1];
24            }
25        }
26        // now its done run a normal loop
27        for(int i=1;i<=n;i++){
28            for(int j=1;j<=m;j++){
29              if(s[i-1]==p[j-1] || s[i-1]=='?'||p[j-1]=='?'){
30                dp[i][j]=dp[i-1][j-1];
31              }
32              else if(s[i-1]=='*'||p[j-1]=='*'){
33                dp[i][j]=dp[i-1][j]||dp[i][j-1];
34              }
35              else{   // no further recursion because there is no way to match these characters
36              dp[i][j] = false;
37              }
38            }
39        }
40     return dp[n][m];
41    }
42};