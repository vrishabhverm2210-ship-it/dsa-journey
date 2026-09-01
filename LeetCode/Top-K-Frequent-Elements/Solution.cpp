1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        unordered_map<int,int>mpp1;  // to store the element of array and their frequency
5        for(int i=0;i<nums.size();i++){
6            mpp1[nums[i]]++;
7        }
8        // now construct the min heap
9        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
10        for(auto i:mpp1){
11            int el=i.first;
12            int freq=i.second;
13            if(pq.size()<k){
14          pq.push({freq,el});
15          continue;
16            }
17            pq.push({freq,el});
18            pq.pop();
19        }
20vector<int>res;
21while(!pq.empty()){
22    pair<int,int>curr=pq.top();
23    pq.pop();
24    res.push_back(curr.second);
25
26}
27reverse(res.begin(),res.end());
28return res;
29    }
30};