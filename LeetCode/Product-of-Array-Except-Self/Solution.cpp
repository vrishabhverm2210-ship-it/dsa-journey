1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        //  vector<int> res(nums.size(),-1);
5         // make the prefix vector
6         int n=nums.size();
7         vector<int>res(nums.size(),1);
8         for(int i=1;i<nums.size();i++){
9           res[i]=res[i-1]*nums[i-1];
10         }
11       int suffix = 1;
12       for(int i=n-1;i>=0;i--){
13        res[i]*=suffix;
14        suffix*=nums[i];
15        
16       }
17
18         return res;
19    }
20};