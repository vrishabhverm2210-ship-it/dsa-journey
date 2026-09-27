1class Solution {
2public:
3
4   void  reverse(vector<int>& nums , int i, int j){
5    while(i<=j){
6        swap(nums[i++],nums[j--]);
7    }
8
9   }
10    void nextPermutation(vector<int>& nums) {
11        int n=nums.size();
12        int res=-1;
13        for(int i=n-2;i>=0;i--)
14        {
15            if(nums[i]<nums[i+1]){
16                res=i;
17                break;
18            }
19            
20        }
21        if(res ==-1) return reverse(nums,0,n-1);
22
23
24      for(int i=n-1;i>=0;i--){
25        if(nums[i]>nums[res]){
26            swap(nums[i],nums[res]);
27            break;
28        }
29      }
30      reverse(nums,res+1,n-1);
31
32    }
33};