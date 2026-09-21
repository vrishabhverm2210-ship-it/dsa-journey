1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n=nums.size();
5    vector<int>res;
6    deque<int>dq;
7    for(int i=0;i<n;i++)
8    {
9      // size se jada toh ni ho gye element
10      if(!dq.empty() && dq.front() <=i-k){
11        dq.pop_front();
12      }
13
14      // now if current element se  chote element hai dq mai (we have to maintain the decreeassing order montonic stack)
15      while(!dq.empty() && nums[dq.back()]<=nums[i]){
16        dq.pop_back();
17      }
18// current element daal do
19      dq.push_back(i);
20      // check first window puri hui ya fir nahi
21      if(i >= k-1){
22        res.push_back(nums[dq.front()]);
23      }
24    }
25    return res;
26    }
27};