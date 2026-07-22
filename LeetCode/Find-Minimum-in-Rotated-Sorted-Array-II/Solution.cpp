1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n=nums.size();
5        int low=0;
6        int high=n-1;
7        int res=INT_MAX;
8        while(low<=high){
9        int mid=low+(high-low)/2;
10        if(nums[mid]<nums[high]){
11            res=min(res,nums[mid]);
12            high=mid-1;
13        }
14        else if(nums[mid]>nums[high]){
15            low=mid+1;
16        }
17
18
19        else{
20            // means we can't decide
21            high--; // because it is safe to move
22          res = min(res, nums[mid]);
23        }  
24        }
25        return res;
26    }
27};