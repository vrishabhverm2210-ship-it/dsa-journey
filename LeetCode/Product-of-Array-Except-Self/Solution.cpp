1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4         vector<int> res(nums.size(),-1);
5         // make the prefix vector
6         vector<int>prefix(nums.size(),1);
7         // start from the 1st index
8         int pro=1;
9         for(int i=1;i<nums.size();i++){
10           prefix[i]=prefix[i-1]*nums[i-1];
11        //    prefix[i]=pro;
12         }
13         // similarly for the suffix
14           vector<int>suffix(nums.size(),1);
15         pro=1;
16         for(int i=nums.size()-2;i>=0;i--){
17           suffix[i]=suffix[i+1]*nums[i+1];
18        //    suffix[i]=pro;
19         }
20         // now all our both the the vectors are created now it's time for the res
21         for(int i=0;i<nums.size();i++){
22            res[i]=prefix[i]*suffix[i];
23         }
24         return res;
25    }
26};