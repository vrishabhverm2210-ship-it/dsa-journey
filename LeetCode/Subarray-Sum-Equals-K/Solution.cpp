1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int sum=0;
5        unordered_map<int,int>mpp1;
6        int res=0;
7        mpp1[0]=1; // ,must codntion
8        for(int i=0;i<nums.size();i++){
9            sum+=nums[i];
10            int freq=mpp1[sum-k];
11            res+=freq;
12            mpp1[sum]++;
13        }
14        return res;
15    }
16};