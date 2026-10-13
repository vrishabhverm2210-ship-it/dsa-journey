1class Solution {
2public:
3bool fun1(vector<int>&nums,int idx,vector<int>&dp){
4        if(idx==nums.size()-1)return true;
5        if(idx>=nums.size())return false;
6        if(dp[idx]!=-1)return dp[idx];
7    for(int i=idx+1;i<= idx + nums[idx];i++){
8           if(fun1(nums,i,dp))return dp[idx]= true;
9    }
10    return dp[idx]=false;
11}
12    bool canJump(vector<int>& nums) {
13        int n=nums.size();
14        vector<int>dp(n+1,-1);
15        return fun1(nums,0,dp);
16    }
17};