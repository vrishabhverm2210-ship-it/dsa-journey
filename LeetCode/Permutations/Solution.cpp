1class Solution {
2public:
3void fun1(vector<int>& nums,int idx,vector<vector<int>>& res){
4    // base condition
5    if(idx==nums.size()){
6        res.push_back(nums);
7        return ;
8    }
9    for(int i=idx;i<nums.size();i++){
10        swap(nums[i],nums[idx]);
11        fun1(nums,idx+1,res);
12        swap(nums[i],nums[idx]);
13    }
14return;
15
16}
17    vector<vector<int>> permute(vector<int>& nums) {
18        vector<vector<int>> res;
19       
20        fun1(nums,0,res);
21        return res;
22    }
23};