1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            // part deciding whether in 1st part or in second
10            if(nums[n-1]<nums[mid]){   // means target first part mai milega
11              if(target==nums[mid]){
12                return mid;
13              }
14              else if(target>nums[mid]){
15                 low=mid+1;   // done
16              }
17              else{   // confusion
18              if(target>nums[n-1]){ // means target hmara first part mai hi lie krta hai
19                 high=mid-1;
20              }
21              else{
22                low=mid+1;  // means second part mai dekhna pdega
23              }
24              }
25            }
26            else{ // 2nd part mai milega
27               if(target==nums[mid]){
28                return mid;
29              }
30              else if(target<nums[mid]){
31                 high=mid-1;
32              }
33              else{   // again confusing part
34              if(target>nums[n-1]){
35                high=mid-1;
36              }
37              else{
38                low=mid+1;
39              }       
40              }
41            }
42        }
43        return -1;
44    }
45};