1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int res=INT_MIN;
5        int high=0;
6        int low=0;
7        int n=nums.size();
8        for(high=0;high<n;high++){
9            // incorrect case
10           if(nums[high]==0){
11               low=high+1;
12           }
13           int len=high-low+1;
14           res=max(res,len);
15        }
16        return res;
17    }
18};