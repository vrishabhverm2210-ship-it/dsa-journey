1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n= nums.size();
5        int bestmin=nums[0];
6        int bestmax=nums[0];
7        int res=nums[0];
8        for(int i=1;i<n;i++){
9            int choice1=nums[i]; // start new
10            int choice2=bestmin*nums[i];
11            int choice3=bestmax*nums[i];
12            bestmax=max({choice1,choice2,choice3});
13            bestmin=min({choice1,choice2,choice3});
14   
15            res=max(res,bestmax);
16        }
17        return res;
18    }
19};