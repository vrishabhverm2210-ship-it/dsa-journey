1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        vector<int>res;
5        int n=nums.size();
6        deque<int>dq;
7        for(int i=0;i<n;i++){
8              // size se jada toh ni ho gye element
9           if(!dq.empty() && dq.front() <=i-k){
10               dq.pop_front();
11            }
12          while(!dq.empty()&& nums[i]>= nums[dq.back()]){    
13               dq.pop_back();
14            }
15  // current element daal do
16      dq.push_back(i);
17
18    if(i>=k-1){
19        res.push_back(nums[dq.front()]);
20    }
21        }
22        return res;
23    }
24};