1class Solution {
2public:
3void fun1(vector<int>& nums,int idx,vector<vector<int>>&res){
4    if(idx==nums.size()){
5        res.push_back(nums);
6        return;
7    }
8    for(int j=idx;j<nums.size();j++){
9        swap(nums[j],nums[idx]);
10        fun1(nums,idx+1,res);
11        swap(nums[j],nums[idx]);
12    
13    }
14    return;
15}
16    vector<vector<int>> permute(vector<int>& nums) {
17        vector<vector<int>>res;
18        fun1(nums,0,res);
19        return res;
20    }
21};