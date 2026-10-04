1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        
5         int n=nums.size();
6          vector<int> res(n,1);
7         for(int i=1;i<n;i++){
8             res[i]=res[i-1]*nums[i-1];
9         }
10         int suffix=1;
11         for(int i=n-1;i>=0;i--){
12            res[i]*=suffix;
13            suffix*=nums[i];
14         }
15         return res;
16    }
17};