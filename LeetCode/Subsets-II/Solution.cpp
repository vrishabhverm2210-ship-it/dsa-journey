1class Solution {
2public:
3void fun1(vector<int>& nums ,int idx,vector<int>&temp,vector<vector<int>>&res){
4    if(idx==nums.size()){
5        res.push_back(temp);
6        return;
7    }
8    int next=idx+1;
9    while(next<nums.size() && nums[idx]==nums[next]){
10        next++;
11    }
12    fun1(nums,next,temp,res);
13    temp.push_back(nums[idx]);
14    fun1(nums,idx+1,temp,res);
15    temp.pop_back();
16    return;
17}
18    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
19         sort(nums.begin(),nums.end());
20           vector<vector<int>>res;
21           vector<int>temp;
22           fun1(nums,0,temp,res);
23           return res;
24    }
25};