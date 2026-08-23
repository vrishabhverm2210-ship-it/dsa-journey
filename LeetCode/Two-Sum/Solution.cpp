1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        // brute force approsach for this
5        int n=nums.size();
6        for(int i=0;i<n-1;i++){
7            for(int j=i+1;j<n;j++){
8                int sum=0;
9                sum=nums[i]+nums[j];
10                if(sum==target)return {i,j};
11            }
12        }
13        return {};
14    }
15};