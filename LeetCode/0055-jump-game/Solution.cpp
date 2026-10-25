class Solution {
public:
bool fun1(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==nums.size()-1)return true;
        if(idx>=nums.size())return false;
        if(dp[idx]!=-1)return dp[idx];
    for(int i=idx+1;i<= idx + nums[idx];i++){
           if(fun1(nums,i,dp))return dp[idx]= true;
    }
    return dp[idx]=false;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return fun1(nums,0,dp);
    }
};