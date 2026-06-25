1class Solution {
2public:
3int sumfun(vector<int>&nums,int n){
4    int sum=0;
5    for(int i=0;i<n;i++){
6        sum+=nums[i];
7    }
8    return sum;
9}
10    int pivotIndex(vector<int>& nums) {
11        int n=nums.size();
12        int sum=sumfun(nums,n);
13        int left=0;
14        int right=0;
15        for (int i=0;i<n;i++){
16          right=sum-left-nums[i];
17          if(left==right){
18            return i;
19          }
20           left+=nums[i];
21        }
22        return -1;
23    }
24};