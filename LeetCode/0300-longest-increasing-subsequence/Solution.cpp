class Solution {
public:
int fun1(vector<int>& nums,int idx,int prev,vector<vector<int>>&dp){
    if(idx==nums.size())return 0;
    if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
    if(prev==-1 || nums[prev]<nums[idx]){
        // two choices
        int c1=fun1(nums,idx+1,prev,dp);
        int c2=1+fun1(nums,idx+1,idx,dp);
        return dp[idx][prev+1]=max(c1,c2);
    }
    return dp[idx][prev+1]=fun1(nums,idx+1,prev,dp);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1);
        for(int i=0;i<=n;i++){
            vector<int>t(n+1,-1);
            dp[i]=t;
        }
        return fun1(nums,0,-1,dp);
    }
};