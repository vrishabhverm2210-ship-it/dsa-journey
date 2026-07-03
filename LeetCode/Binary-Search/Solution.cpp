1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low=0;
5        int high=nums.size()-1;
6        while(high>=low){
7            int mid= (low+high)/2;
8            if(nums[mid]==target)return mid;
9            else if(nums[mid]<target)low=mid+1;
10            else{
11                high=mid-1;
12            }
13        }
14        return -1;
15    }
16};