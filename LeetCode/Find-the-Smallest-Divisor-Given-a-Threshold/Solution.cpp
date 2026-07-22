1class Solution {
2public:
3bool ispossible(vector<int>& nums, int threshold,int mid){
4    int sum=0;
5    for(int i=0;i<nums.size();i++){
6       sum =sum +ceil((double)nums[i] / mid);
7        if(sum>threshold)return false;
8    }
9    return true;
10}
11    int smallestDivisor(vector<int>& nums, int threshold) {
12        int low=1;
13        int high=0;
14        for(int i=0;i<nums.size();i++){
15            high=max(high,nums[i]);
16        }
17        int res=-1;
18        while(low<=high){
19            int mid=low+(high-low)/2;
20            if(ispossible(nums,threshold,mid)){
21                // for more min
22                res=mid;
23                high=mid-1;
24            }
25            else{
26                low=mid+1;
27            }
28        }
29        return res;
30
31    }
32};