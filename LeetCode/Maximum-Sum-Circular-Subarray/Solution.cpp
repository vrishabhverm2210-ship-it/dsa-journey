1class Solution {
2public:
3int fun1(vector<int>& nums){
4    int bestmaxi=nums[0];
5    int res=nums[0];
6    for(int i=1;i<nums.size();i++){
7        int c1=nums[i];
8        int c2=nums[i]+bestmaxi;
9        bestmaxi=max(c1,c2);
10        res=max(res,bestmaxi);
11    }
12    return res;
13}
14int fun2(vector<int>& nums){
15    int bestmini=nums[0];
16    int res=nums[0];
17    for(int i=1;i<nums.size();i++){
18        int c1=nums[i];
19        int c2=nums[i]+bestmini;
20        bestmini=min(c1,c2);
21        res=min(res,bestmini);
22    }
23    return res;
24}
25    int maxSubarraySumCircular(vector<int>& nums) {
26        int sumtotal=0;
27        int maxi1=INT_MIN;
28        for(int i=0;i<nums.size();i++){
29            sumtotal+=nums[i];
30            maxi1=max(maxi1,nums[i]);
31        }
32        int maxi=fun1(nums);
33            if(maxi<0)return maxi;
34        int mini=fun2(nums);
35        // if(sumtotal==mini)return maxi1;
36        int c1=sumtotal-mini;
37        int c2=maxi;
38        int res=max(c1,c2);
39        return res;
40    
41    }
42};