1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        // SYNTAX OF MIN HEAP
5      priority_queue<int,vector<int>,greater<int>>pq;
6      for(int i=0;i<k;i++){   //TC=>O(log(k))
7        pq.push(nums[i]);
8      }
9      // Now check (whether orr elements dalne chahiye ya nahi)
10      for(int i=k;i<nums.size();i++){// TC=> O(n-k)
11        // if(nums[i]<=pq.top())continue;
12          pq.push(nums[i]);
13        pq.pop();                     // TC=>O(log(k)+log(k)
14      
15      }
16      return pq.top();
17    }
18};
19
20//space =>O(k)