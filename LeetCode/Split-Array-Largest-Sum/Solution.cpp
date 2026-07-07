1class Solution {
2public:
3bool isPossible(vector<int>& nums, int k, int mid){
4    int count=1;
5    int sum=0;
6    for(int i=0;i<nums.size();i++){
7        sum+=nums[i];
8        if(sum>mid){
9            count++;
10            sum=nums[i];
11            if(count>k)return false;
12        }
13    }
14return true;
15}
16    int splitArray(vector<int>& nums, int k) {
17        //  determine the search space
18        int low=INT_MIN;
19        int high=0;
20        for(int i=0;i<nums.size();i++){
21            high+=nums[i];
22            low=max(low,nums[i]);
23        }
24     int res=-1;
25     while(low<=high){
26        int mid=low+(high-low)/2;
27        if(isPossible(nums,k,mid)){
28            res=mid;
29            high=mid-1;
30        }
31        else
32        {
33            low=mid+1;
34        }
35     }
36return res;
37    }
38};