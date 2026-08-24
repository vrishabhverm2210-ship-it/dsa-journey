1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4       priority_queue<int,vector<int>,greater<int>>pq;
5       // push and the first k element into it and for rest of thr elements do processing
6       for(int i=0;i<nums.size();i++){
7        if(pq.size()<k){
8            pq.push(nums[i]);
9            continue;
10        }
11        pq.push(nums[i]);
12        pq.pop();
13       }
14       return pq.top();
15
16            }
17};