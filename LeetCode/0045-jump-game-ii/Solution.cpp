class Solution {
public:
int fun1(vector<int>&nums,int idx,vector<int>&dp){
    if(idx>=nums.size()-1)return 0;
    // if(idx>=nums.size())return 0;
if(dp[idx]!=-1)return dp[idx];
int mini=   INT_MAX;
    for(int i=idx+1;i<=idx+nums[idx];i++){
        int jumps=fun1(nums,i,dp);
    if(jumps!=INT_MAX){
         mini=min(1+jumps,mini);
    }
        

    }
    return dp[idx]=mini;
}
    int jump(vector<int>& nums) {
           int n=nums.size();
        vector<int>dp(n+1,-1);
        return fun1(nums,0,dp);
         
    
    }
};