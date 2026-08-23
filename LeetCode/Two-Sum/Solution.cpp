1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int,int>mpp1; //O(N)
5        int n=nums.size();
6        for(int i=0;i<n;i++){     // O(N)
7            int needed=target-nums[i];
8            if(mpp1.find(needed)!=mpp1.end()){
9                return {i,mpp1[needed]};
10            }
11            mpp1[nums[i]]=i;
12        }
13        return {};
14    }
15};