1class Solution {
2public:
3    int missingNumber(vector<int>& nums) {
4        unordered_map<int,int>mpp1;
5        for(int i=0;i<nums.size();i++){
6            mpp1[nums[i]]=1;
7        }
8        int n=nums.size();
9        for(int i=0;i<=n;i++){
10            if(mpp1.find(i)!=mpp1.end())continue;
11            else{
12                return i;
13            }
14        }
15        return -1;
16    }
17};