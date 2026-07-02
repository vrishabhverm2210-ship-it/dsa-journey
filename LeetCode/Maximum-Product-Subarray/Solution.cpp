1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int bestmaxi=nums[0];
5        int bestmini=nums[0];
6        int res=nums[0];
7        for(int i=1;i<nums.size();i++){
8            int c1=nums[i];
9            int c2=nums[i]*bestmaxi;
10            int c3=nums[i]*bestmini;
11            bestmaxi=max({c1,c2,c3});
12            bestmini=min({c1,c2,c3});
13            res=max({res,bestmaxi,bestmini});
14        }
15        return res;
16    }
17};