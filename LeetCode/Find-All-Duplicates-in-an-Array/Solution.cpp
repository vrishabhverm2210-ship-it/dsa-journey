1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4        int n =nums.size();
5        // use array itself
6        vector<int>res;
7        for(int i=0;i<n;i++){
8            int j=abs(nums[i])-1;
9              if(nums[j]<0)res.push_back(abs(nums[i]));
10             else{
11                nums[j]*=-1;
12             }
13        }
14        return res;
15    }
16};