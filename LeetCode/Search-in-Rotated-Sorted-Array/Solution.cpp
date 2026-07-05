1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        while(low<=high){
8            int mid=low+(high-low)/2;
9            if(nums[mid]>nums[n-1]){// 2nd part
10                if(nums[mid]==target)return mid;
11                else if(nums[mid]<target){
12                    low=mid+1;
13                }
14                else{  // two choices(we have to decidde by target itself)
15
16                if(target>nums[n-1]){  // means target lies in second part
17                    high=mid-1;
18
19                }
20                else{
21                    low=mid+1;
22                }
23                }
24            }
25            else{
26                if(nums[mid]==target){
27                    return mid;
28                }
29                else if(nums[mid]>target){
30                    high=mid-1;
31                }
32                else{
33                    if(target>nums[n-1]){
34                        high=mid-1;
35                    }
36                    else{
37                        low=mid+1;
38                    }
39                }
40            }
41        }
42        return -1;
43    }
44};