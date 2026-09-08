1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int n= nums.size();
5        unordered_map<int,int>mpp1;
6        for(int i=0;i<n;i++)mpp1[nums[i]]++;
7        for(auto i:mpp1){
8            if(i.second>n/2)return i.first;
9
10        }
11        return -1;
12    }
13};