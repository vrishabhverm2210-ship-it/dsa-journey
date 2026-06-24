1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int bestending=nums[0];
5        int ans=nums[0];
6        for(int i=1;i<nums.size();i++){
7            int choice1=bestending+nums[i]; // continue journey
8            int choice2=nums[i];            // start new
9         bestending= max(choice1,choice2); 
10         ans = max(ans,bestending);
11        }
12        return ans;
13    }
14};