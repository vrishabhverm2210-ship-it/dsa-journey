1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int left=0;
5        int right=0;
6        int n=nums.size();
7        int sum=0;
8        for(int i=0;i<n;i++){
9            sum+=nums[i];
10        }
11        for(int i=0;i<n;i++){
12          right=sum-left-nums[i];
13          if(left==right)return i;
14          left+=nums[i];
15        }
16        return -1;
17    }
18};