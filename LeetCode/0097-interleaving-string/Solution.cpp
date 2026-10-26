class Solution {
public:
bool fun1(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp){
if(k==s3.size()){
    return true;
}
if(dp[i][j]!=-1)return dp[i][j];
bool ans=false;
    if(i<s1.size()&&s1[i]==s3[k]){
       ans =ans|| fun1(s1,s2,s3,i+1,j,k+1,dp);
    }
 if(j<s2.size()&&s2[j]==s3[k]){
      ans =ans|| fun1(s1,s2,s3,i,j+1,k+1,dp);
    }
return dp[i][j]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        // impossible case
        if(s1.size()+s2.size()!=s3.size())return false;
int n=s1.size();
int m=s2.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun1(s1,s2,s3,0,0,0,dp);
    }
};