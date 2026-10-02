1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        int n=nums.size();
5        int ans=n;
6        for(int i=0;i<n;i++){
7            ans^=i;
8            ans^=nums[i];
9        }
10        return ans;
11    }
12};