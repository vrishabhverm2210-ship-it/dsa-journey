1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int low=0;
5        int high=nums.size()-1;
6        int res=-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9           if(mid==nums.size()-1){
10            res = mid;
11            break;
12           }
13           else if(nums[mid]<nums[mid+1]){
14            low=mid+1;
15           }
16           else{
17            res=mid;
18            high=mid-1;
19           }
20        }
21return res;
22    }
23};