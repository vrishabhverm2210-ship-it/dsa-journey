1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4       int bestmin=nums[0];
5       int bestmax=nums[0];
6       int ans=nums[0];
7       for(int i=1;i<nums.size();i++){
8        int choice1=nums[i];  // sirf no hi lelo
9        int choice2=nums[i]*bestmin;
10        int choice3=nums[i]*bestmax;
11        bestmin=min({choice1,choice2,choice3});
12        bestmax=max({choice1,choice2,choice3});
13        ans=max({bestmax,ans, bestmin});
14       } 
15       return ans;
16    }
17};