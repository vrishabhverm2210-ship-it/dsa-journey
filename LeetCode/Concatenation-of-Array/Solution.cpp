1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n=nums.size();
5         vector<int> res;
6         for(int i=0;i<nums.size();i++){
7            res.push_back(nums[i]);
8         }
9          for(int i=0;i<nums.size();i++){
10            res.push_back(nums[i]);
11         }
12return res;
13    }
14};