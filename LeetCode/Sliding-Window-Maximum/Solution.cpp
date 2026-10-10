1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4          vector<int> res;
5          deque<int>dq;
6          int n=nums.size();
7          for(int i=0;i<n;i++){
8            if(dq.empty()){
9                dq.push_back(i);
10                
11            }
12            while(!dq.empty() && nums[dq.back()] <= nums[i]){
13             dq.pop_back();
14            }
15            dq.push_back(i);
16            if(i-dq.front()>=k)dq.pop_front();
17            if(i-k+1>=0){
18             res.push_back(nums[dq.front()]);
19            }
20          }
21          return res;
22    }
23};