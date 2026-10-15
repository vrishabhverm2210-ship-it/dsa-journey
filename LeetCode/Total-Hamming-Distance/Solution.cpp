1class Solution {
2public:
3    int totalHammingDistance(vector<int>& nums) {
4        int n=nums.size();
5        int ans=0;
6        for(int i=0;i<32;i++){
7int ones=0;
8            for(auto num:nums){
9                if((num>>i) &1){
10ones++;
11                }
12            }
13            ans+=ones*(n-ones);
14        }
15        return ans;
16    }
17};