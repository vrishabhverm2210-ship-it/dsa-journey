1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        int res=-1;
8        while(low<=high){
9            int mid=low+(high-low)/2;
10            if(mid==n-1){
11                res=n-1;
12                return res;
13            }
14            else if(nums[mid]<nums[mid+1]){
15                low=mid+1;
16            }
17            else{
18                res=mid;
19                high=mid-1;
20            }
21            }
22
23        return res;
24    }
25};