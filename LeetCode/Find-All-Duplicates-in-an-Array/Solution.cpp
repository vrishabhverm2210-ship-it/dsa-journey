1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4        // if mai hashmap ki constant space bana du
5        int n=nums.size();
6        unordered_map<int,int>mpp1;
7        for(int i=0;i<n;i++){
8            mpp1[nums[i]]++;
9        }
10        vector<int>res;
11        for(auto i:mpp1){
12            if(i.second==2)res.push_back(i.first);
13        }
14        return res;
15    }
16};