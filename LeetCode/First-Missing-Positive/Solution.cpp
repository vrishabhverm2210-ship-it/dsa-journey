1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n=nums.size();
5       for(int i=0;i<n;i++){
6        while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
7                       swap(nums[i],nums[nums[i]-1]);
8        }
9       }
10       for(int i=0;i<n;i++){
11        if(nums[i]!=i+1){
12            return i+1;
13        }
14       }
15       return n+1;
16    }
17};