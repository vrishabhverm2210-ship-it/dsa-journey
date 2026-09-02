1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int bestmaxi=nums[0];
5        int res=nums[0];
6        for(int i=1;i<nums.size();i++){
7            int c1=nums[i];
8            int c2=nums[i]+bestmaxi;
9            bestmaxi=max(c1,c2);
10            res=max(res,bestmaxi);
11        }
12        return res;
13    }
14};