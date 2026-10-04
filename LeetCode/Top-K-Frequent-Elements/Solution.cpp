1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        vector<int> res;
5        int n=nums.size();
6        unordered_map<int,int>mpp1;
7        for(int i=0;i<n;i++){
8            mpp1[nums[i]]++;
9        }
10        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
11
12        for(auto i:mpp1){
13            if(pq.size()<k){
14               pq.push({i.second,i.first});
15               continue;
16            }
17            pq.push({i.second,i.first});
18            pq.pop();
19        }
20        while(!pq.empty()){
21            res.push_back(pq.top().second);
22            pq.pop();
23        }
24        return res;
25    }
26};