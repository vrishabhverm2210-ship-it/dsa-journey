class Solution {
public:
int fun1(string text1, string text2,int n,int m, vector<vector<int>>&dp){
   if(n==0||m==0)return 0;
   if(dp[n][m]!=-1)return dp[n][m];
    if(text1[n-1]==text2[m-1]){
      return  dp[n][m]=  1+fun1(text1,text2,n-1,m-1,dp);
    }
  
        int c1=fun1(text1,text2,n-1,m,dp);
        int c2=fun1(text1,text2,n,m-1,dp);
        return dp[n][m]= max(c1,c2);
   

}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(text1.size()+1);
        for(int i=0;i<=text1.size();i++){
            vector<int>t(text2.size()+1,-1);
            dp[i]=t;
        }
    //    return fun1(text1,text2,text1.size(),text2.size(),dp); 
    //      // return fun1(text1,text2,n,m,dp);
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                  dp[i][j]=  max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
return dp[n][m];
    }
};