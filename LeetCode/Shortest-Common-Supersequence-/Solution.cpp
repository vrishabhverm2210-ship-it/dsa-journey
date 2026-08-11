1class Solution {
2public:
3    string shortestCommonSupersequence(string text1, string text2) {
4         // code here
5          int n=text1.size();
6          int m=text2.size();  
7          vector<vector<int>>dp(n+1);
8        for(int i=0;i<=n;i++){
9             vector<int>t(m+1,-1);
10             dp[i]=t;
11        }
12        // initialise according to the base case
13        for(int i=0;i<=n;i++){
14            dp[i][0]=0;
15        }
16        for(int i=0;i<=m;i++){
17            dp[0][i]=0;
18        }
19        // now fill the remaining pllaces of matrix using the normal loops
20        for(int i=1;i<=n;i++){
21            for(int j=1;j<=m;j++){
22                if(text1[i-1]==text2[j-1]){
23                    dp[i][j]=1+dp[i-1][j-1];
24                }
25                else{
26                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
27                }
28            }
29        }
30        // now we have to backtrack the matrix
31        int i=n;
32        int j=m;
33        string s="";
34        while(i>0 && j>0){
35          if(text1[i-1]==text2[j-1]){
36            s.push_back(text1[i-1]);
37            i--;
38            j--;
39          }
40          else {
41            if(dp[i-1][j]>dp[i][j-1]){
42                s.push_back(text1[i-1]);
43                i--;
44            }
45            else{
46                s.push_back(text2[j-1]);
47                j--;
48            }
49          }
50        }
51        while(i>0){
52            s.push_back(text1[i-1]);
53                i--;
54            
55        }
56        while(j>0){
57  s.push_back(text2[j-1]);
58                j--;
59        }
60        reverse(s.begin(), s.end());
61        return s;
62    }
63};