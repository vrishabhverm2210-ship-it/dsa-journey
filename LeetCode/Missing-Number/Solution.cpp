1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        // let's try to build the XOR solution
5        int n=nums.size();
6        int ans=n;
7        for(int i=0;i<n;i++){
8        ans=ans^i;
9        ans=ans^nums[i];
10        }
11        return ans;
12    }
13};