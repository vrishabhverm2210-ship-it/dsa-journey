1class Solution {
2public:
3    string shortestCommonSupersequence(string str1, string str2) {
4         
5       
6    int n=str1.size();
7        int m=str2.size();
8        // make the dp vector
9        vector<vector<int>>dp(n+1);
10        for(int i=0;i<=n;i++){
11            vector<int>t(m+1);
12            dp[i]=t;
13        }
14        
15        // now intialise the vector 0th row and 0th col , according to the base case
16        for(int i=0;i<=n;i++){
17            dp[i][0]=0;
18        }
19        for(int i=0;i<=m;i++){
20            dp[0][i]=0;
21        }
22        // now run a nested loop for filling the remaining spots of array
23        for(int i=1;i<=n;i++){
24            for(int j=1;j<=m;j++){
25                if(str1[i-1]==str2[j-1]){
26                    dp[i][j]=1+dp[i-1][j-1];
27                }
28                else{
29                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
30                }
31            }
32        }
33      string res="";
34      int i=n;
35      int j=m;
36      while(i>0 && j>0){
37        if(str1[i-1] == str2[j-1]){
38            res.push_back(str1[i-1]);
39            i--;
40            j--;
41        }
42        else {
43            if(dp[i-1][j]>dp[i][j-1]){
44            res.push_back(str1[i-1]);
45            i--;
46        }
47        else{
48            res.push_back(str2[j-1]);
49            j--;
50        }
51        }
52      }
53      while(i>0){
54        res.push_back(str1[i-1]);
55        i--;
56        
57      }
58      while(j>0){
59        res.push_back(str2[j-1]);
60        j--;
61     
62      }
63        reverse(res.begin(), res.end());
64      return res;
65    }
66};