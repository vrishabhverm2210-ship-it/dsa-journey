1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int n=nums.size();
6        return nums[n-k];
7    }
8};