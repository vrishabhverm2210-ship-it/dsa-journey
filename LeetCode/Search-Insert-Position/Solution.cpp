1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=nums.size()-1;
7        while(low<=high){
8         int mid=low+(high-low)/2;
9         if(nums[mid]==target)return mid;
10         else if(nums[mid]>target){
11          high=mid-1;
12         }
13         else{
14            low=mid+1;
15         }
16        }
17        return low;
18    }
19};