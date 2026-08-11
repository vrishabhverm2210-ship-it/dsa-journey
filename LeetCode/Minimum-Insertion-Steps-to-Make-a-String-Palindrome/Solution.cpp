1class Solution {
2public:
3    int minInsertions(string s1) {
4        // code here
5        string s2=s1;
6        reverse(s2.begin(),s2.end());
7           int n=s1.size();
8        int m=s2.size();
9        // make the dp vector
10        vector<vector<int>>dp(n+1);
11        for(int i=0;i<=n;i++){
12            vector<int>t(m+1);
13            dp[i]=t;
14        }
15        
16        // now intialise the vector 0th row and 0th col , according to the base case
17        for(int i=0;i<=n;i++){
18            dp[i][0]=0;
19        }
20        for(int i=0;i<=m;i++){
21            dp[0][i]=0;
22        }
23        // now run a nested loop for filling the remaining spots of array
24        for(int i=1;i<=n;i++){
25            for(int j=1;j<=m;j++){
26                if(s1[i-1]==s2[j-1]){
27                    dp[i][j]=1+dp[i-1][j-1];
28                }
29                else{
30                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
31                }
32            }
33        }
34        return (n-dp[n][m]);
35    }
36};