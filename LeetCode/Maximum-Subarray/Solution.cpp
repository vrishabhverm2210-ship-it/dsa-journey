1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int n=nums.size();
5        int res=nums[0];
6        int bestpossible=nums[0];
7        for(int i=1;i<n;i++){
8            int choice1= nums[i];   // start a new journey ignorring your past
9            int choice2=bestpossible+nums[i];  // continue journey along with ur past
10            bestpossible =max(choice1,choice2);
11            res=max(res,bestpossible);
12        }
13        return res;
14    }
15};