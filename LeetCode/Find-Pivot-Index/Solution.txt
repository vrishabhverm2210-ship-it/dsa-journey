1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        // find  total sum first
5        int sum=0;
6        for(int i=0;i<nums.size();i++){
7            sum+=nums[i];
8        }
9        int left=0;
10        int right;
11        for(int i=0;i<nums.size();i++){
12             right=sum-left-nums[i];
13             if(left==right)return i;
14
15            left+=nums[i];
16          
17        }
18      return -1;  
19    }
20};