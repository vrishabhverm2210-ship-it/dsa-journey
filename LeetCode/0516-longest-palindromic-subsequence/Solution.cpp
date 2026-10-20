class Solution {
public:
    int longestPalindromeSubseq(string s1) {
         string s2=s1;
         reverse(s2.begin(),s2.end());
    int n=s1.size();
        int m=s2.size();
        // make the dp vector
        vector<vector<int>>dp(n+1);
        for(int i=0;i<=n;i++){
            vector<int>t(m+1);
            dp[i]=t;
        }
        
        // now intialise the vector 0th row and 0th col , according to the base case
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        // now run a nested loop for filling the remaining spots of array
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};