1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            if(nums[mid]==target)return mid;
10            // now firstly determine the half ,whether our middle belongs to first half or second
11            else if(nums[mid] > nums[n-1]){
12                // first half
13                if(target>nums[mid]){
14                    low=mid+1;
15                }
16                else{
17                    // there are two possible condition
18                    if(target >nums[n-1]){
19                        high=mid-1;
20                    }
21                    else{
22                        low=mid+1;
23                    }
24                }
25            }
26            else{
27                if(target<nums[mid]){
28                    high=mid-1;
29                }
30                else{
31                    //  // there are two possible condition
32                    if(target>nums[n-1]){
33                        high=mid-1;
34                    }
35                    else{
36                        low=mid+1;
37                    }
38                }
39            }
40        }
41        return -1;
42    }
43};