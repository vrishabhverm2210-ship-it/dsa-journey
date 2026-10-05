1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n=nums.size();
5        unordered_map<int,int>mpp1;
6        for(int i=0;i<n;i++){
7            mpp1[nums[i]]++;
8        }
9
10        for(int i=1;i<=n+1;i++ ){
11            if(mpp1.find(i)==mpp1.end()){
12                return i;
13            }
14        }
15        return -1;
16    }
17};