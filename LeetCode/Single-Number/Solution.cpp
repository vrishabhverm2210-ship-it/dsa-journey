1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int n=nums.size();
5        int ans=nums[0];
6        for(int i=1;i<n;i++){
7            ans^=nums[i];
8        }
9        return ans;
10    }
11};