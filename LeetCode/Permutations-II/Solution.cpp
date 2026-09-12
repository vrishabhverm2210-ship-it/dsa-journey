1class Solution {
2public:
3void fun1(vector<int>& nums,vector<int>&temp, vector<vector<int>>&res,int idx){
4    if(idx==nums.size()){
5        res.push_back(nums);
6        return;
7    }
8    // values already used at this level
9        set<int> used;
10    for(int i=idx;i<nums.size();i++){
11       if(used.find(nums[i])!=used.end()){
12           continue;
13       }
14       used.insert(nums[i]);
15        swap(nums[idx],nums[i]);
16        fun1(nums,temp,res,idx+1);
17        swap(nums[idx],nums[i]);
18    }
19}
20    vector<vector<int>> permuteUnique(vector<int>& nums) {
21         vector<vector<int>>res;
22         vector<int>temp;
23         int n=nums.size();
24         fun1(nums,temp,res,0);
25         return res;
26    }
27};