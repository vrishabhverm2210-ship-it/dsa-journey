class Solution {
public:
int fun1(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>& grid){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    // unsafe condition
    if(i>=n||i<0||j>=m||j<0)return 0;
    if(grid[i][j]==1){
        return 0;
    }   
    return dp[i][j]=fun1(i+1,j,n,m,dp,grid)+ fun1(i,j+1,n,m,dp,grid);
}
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
     
        int n=grid.size();
        int m=grid[0].size();
           if(grid[n-1][m-1]==1)return 0;
           vector<vector<int>>dp(n+1);
        for(int i=0;i<=n;i++){
            vector<int>t(m+1,-1);
            dp[i]=t;
        }
        return fun1(0,0,n,m,dp,grid);
    }
};