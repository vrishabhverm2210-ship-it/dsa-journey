1class Solution {
2public:
3
4   void  reverse(vector<int>& nums , int i, int j){
5    while(i<=j){
6        swap(nums[i++],nums[j--]);
7    }
8
9   }
10    void nextPermutation(vector<int>& nums) {
11           int n=nums.size();
12        // step 1: for finding breaking line
13     int ind= -1;
14     for(int i=n-2;i>=0;i--){
15        if(nums[i]<nums[i+1]){
16            ind=i;
17            break;
18        }
19     }
20     // edge case : if we would not able to find any breaking line
21     if(ind ==-1){
22          return   reverse(nums,0,n-1);
23     }
24     // step 2: just bda dhundhna hai
25     for(int i=n-1;i>=0;i--){
26        if(nums[i]>nums[ind]){
27            swap(nums[i],nums[ind]);
28            break;
29        }
30     }    // step3 (sort it)
31     reverse(nums,ind+1,n-1);
32
33
34    }
35};