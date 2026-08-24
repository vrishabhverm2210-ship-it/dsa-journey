1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        while(high>=low){
8            int mid=low+(high-low)/2;
9            if(nums[mid]==target)return mid;
10            else if(nums[mid]>target)
11            {
12                high=mid-1;
13            }
14            else
15            {
16                low=mid+1;
17            }
18        }
19        return -1;
20    }
21};