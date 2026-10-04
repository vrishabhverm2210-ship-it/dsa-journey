1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            // 1st half
10            if(nums[mid]==target)return mid;
11         else if(nums[mid]>nums[n-1]){
12                if(target>nums[mid]){
13                    low=mid+1;
14                }
15                else{
16                    if(target>nums[n-1]){
17                        high=mid-1;
18                    }
19                    else{
20                        low=mid+1;
21                    }
22                }
23            }
24            // else second half
25            else{
26               if(target<nums[mid]){
27                     high=mid-1;
28               }
29               else{
30                if(target<=nums[n-1]){
31                    low=mid+1;
32                }
33                else{
34                    high=mid-1;
35                }
36               }
37            }
38        }
39        return -1;
40    }
41};