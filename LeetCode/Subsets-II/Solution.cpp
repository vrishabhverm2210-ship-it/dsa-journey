1class Solution {
2public:
3void fun1(vector<int>&nums,vector<int>&temp,vector<vector<int>>&res,int idx){
4    if(idx==nums.size()){
5        res.push_back(temp);
6        return;
7    }
8    // firstly no take case along with skipping the duplicates
9
10    int next=idx+1;
11    while(next<nums.size() && nums[next]==nums[idx]){
12        next++;
13    }
14    fun1(nums,temp,res,next);
15    // now take case
16    temp.push_back(nums[idx]);
17    fun1(nums,temp,res,idx+1);
18    temp.pop_back();
19    return ;
20}
21    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
22        sort(nums.begin(),nums.end());
23        vector<vector<int>> res;
24        vector<int>temp;
25        int idx=0;
26        fun1(nums,temp,res,idx);
27        return res;
28    }
29};