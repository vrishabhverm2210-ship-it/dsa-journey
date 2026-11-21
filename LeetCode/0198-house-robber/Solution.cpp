class Solution {
public:
int fun1(vector<int>& nums,int idx,int flag,vector<vector<int>>&dp){
     if(nums.size()==idx)return 0;
if(dp[idx][flag]!=-1){
    return dp[idx][flag];
}
     if(flag==0){
        return dp[idx][flag]=fun1(nums,idx+1,1,dp);
     }
     int c1=nums[idx]+fun1(nums,idx+1,0,dp);
     int c2=fun1(nums,idx+1,1,dp);
     return dp[idx][flag]=max(c1,c2);
}
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(2,-1));
        return fun1(nums,0,1,dp);
    }
};