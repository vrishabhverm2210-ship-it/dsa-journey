1class Solution {
2public:
3    void rotate(vector<int>& nums, int k) {
4        vector<int>temp1(nums.size());
5        for(int i=0;i<nums.size();i++){
6            temp1[(i+k)%nums.size()]=nums[i];  
7        }
8        // copy temp into nums
9        nums=temp1;
10    }
11};