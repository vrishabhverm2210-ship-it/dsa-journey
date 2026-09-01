1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7    while(low<=high){
8            int mid=low+(high-low)/2;
9            if(nums[mid]==target)return mid;
10            if(nums[mid]<=nums[n-1]){
11                // first half
12                if(nums[mid]<target){
13                    if(target>nums[n-1]){
14                        high=mid-1;
15                    }
16                    else{
17                        low=mid+1;
18                    }
19                }
20                else{
21                    high=mid-1;
22                }
23            }
24            else{//second half
25                if(nums[mid]<target){
26                    low=mid+1;
27                }
28                else{
29                    if(target>nums[n-1]){
30                        high=mid-1;
31                    }
32                    else{
33                        low=mid+1;
34                    }
35                }
36            }
37        }
38        return -1;
39    }
40};